# Extrahieren versteckter Nachrichten aus BMP-Bildern – Erklärung der Funktion `ExtractMessage()`

Dieses Dokument erklärt die Funktionsweise der `ExtractMessage()`-Funktion aus dem Projekt `zSteganizer`.  
Sie zeigt, wie Bits aus dem Pixeldatenbereich eines BMP-Bildes gelesen und in Text zurückverwandelt werden.

---

## Was macht die Funktion?

- Öffnet eine 24-Bit BMP-Bilddatei
- Liest alle Bytes der Pixeldaten und extrahiert jeweils das niederwertigste Bit (LSB)
- Hängt diese Bits zu einer Binärzeichenkette zusammen
- Stoppt, sobald der 16-Bit Endmarker `1111111111111110` erkannt wird
- Wandelt die Binärdaten zurück in lesbaren Text

---

## Code-Erklärung

```cpp
std::ifstream inFile(inputFile, std::ios::binary);
```
Öffnet die BMP-Datei im binären Lesemodus.

```cpp
std::vector<char> header(54);
inFile.read(header.data(), header.size());
```
Liest den BMP-Header mit 54 Bytes. Dieser Teil wird übersprungen, da die versteckten Daten in den Pixeldaten stecken.

```cpp
if (header[0] != 'B' || header[1] != 'M') {
    std::cerr << "Error: Not a valid BMP file.\n";
    return "";
}
```
Überprüft, ob die Datei die korrekte BMP-Signatur „BM“ enthält.

```cpp
std::string binaryMessage = "";
char byte;
```
Initialisiert eine leere Binärzeichenkette und eine temporäre Variable zum Lesen der Bytes.

```cpp
while (inFile.get(byte)) {
    binaryMessage += (byte & 1) ? '1' : '0';
```
Extrahiert das niederwertigste Bit jedes gelesenen Bytes mit `(byte & 1)` und speichert es als `'0'` oder `'1'`.

```cpp
    if (binaryMessage.size() >= 16 &&
        binaryMessage.substr(binaryMessage.size() - 16) == "1111111111111110") {
        binaryMessage = binaryMessage.substr(0, binaryMessage.size() - 16);
        break;
    }
}
```
Sobald der 16-Bit Endmarker erkannt wird, wird dieser entfernt und die Schleife abgebrochen.

```cpp
std::string message = "";
for (size_t i = 0; i + 7 < binaryMessage.size(); i += 8) {
    std::string byteStr = binaryMessage.substr(i, 8);
    char c = static_cast<char>(std::stoi(byteStr, nullptr, 2));
    message += c;
}
```
Wandelt jede 8-Bit-Sequenz in ein ASCII-Zeichen um und setzt die Nachricht zusammen.

```cpp
return message;
```
Gibt die rekonstruierte Nachricht als `std::string` zurück.

---

## Zusammenfassung

`ExtractMessage()` liest versteckte Bits aus einem BMP-Bild,  
erkennt den Endmarker und baut die ursprüngliche Nachricht aus der Binärfolge wieder zusammen.  
Sie ist das Gegenstück zu `EmbedMessage()` und funktioniert leise, effizient und zuverlässig.



Documentation written by: Jose Luis Ocana (GitHub: [0xZorro](https://github.com/0xZorro))  
Last updated: April 2025