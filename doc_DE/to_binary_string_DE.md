# Umwandlung von Text in Binärformat in zSteganizer – Erklärung der Funktion `to_binary_string()`

In diesem Dokument erklären ich im Detail, wie die Funktion `to_binary_string()` funktioniert.  
Sie wird im Projekt `zSteganizer` verwendet, um menschenlesbaren Text in eine Folge von Binärzeichen (1 und 0) zu verwandeln,  
die anschließend in einem BMP-Bild mithilfe von Least-Significant-Bit-Steganografie (LSB) versteckt werden können.

---

## Was macht die Funktion?

Sie nimmt einen Text – z. B. `"Hello world"` – und erzeugt daraus eine Zeichenkette wie:
```
0100100001100101011011000110110001101111001000000111011101101111011100100110110001100100
```

Das ist die Binärdarstellung des gesamten Textes – inklusive Leerzeichen und Sonderzeichen.  
Zusätzlich wird ein spezieller 16-Bit Endmarker (`1111111111111110`) angehängt,  
damit man beim Auslesen später weiß, wo die Nachricht endet.

---

## Zeile-für-Zeile Erklärung

```cpp
std::string to_binary_string(const std::string& message) {
```
Startet eine Funktion, die einen Text entgegennimmt und als Ausgabe eine Kette aus '0' und '1' zurückgibt.

```cpp
    std::string binary;
```
Bereitet eine leere Zeichenkette vor, in der die Bitfolge gesammelt wird.

```cpp
    for (char c : message) {
```
Durchläuft jedes Zeichen im Text nacheinander.

```cpp
        for (int i = 7; i >= 0; --i) {
```
Durchläuft die 8 Bits jedes Zeichens – vom höchsten Bit (links) bis zum niedrigsten (rechts).

```cpp
            binary += ((c >> i) & 1) ? '1' : '0';
```
Schiebt das aktuelle Bit an die rechte Position, maskiert alle anderen weg,  
und fügt entweder eine '1' oder eine '0' an die Bitfolge an.

```cpp
        }
    }
```
Beendet die beiden Schleifen.

```cpp
    binary += "1111111111111110";
```
Hängt einen 16-Bit Endmarker an, damit beim Auslesen erkannt wird, wann der Text endet.

```cpp
    return binary;
}
```
Gibt die gesamte Binärzeichenkette zurück.

---

## Beispiel mit `"Hi"`

Eingabe: `"Hi"`  
Zeichen:
- `'H'` → ASCII 72 → `01001000`
- `'i'` → ASCII 105 → `01101001`

Zusammen:
```
0100100001101001
```

Mit Endmarker:
```
01001000011010011111111111111110
```

---

## Warum ist das wichtig?

Steganografie funktioniert nur, wenn man Daten auf Bit-Ebene kontrollieren kann.  
Diese Funktion wandelt eine lesbare Nachricht in eine Bitfolge um,  
die unsichtbar in den Bilddaten versteckt werden kann.  
Der Endmarker hilft beim späteren Auslesen.

---

## Ergebnis

Eine verlässliche, umkehrbare und bitgenaue Darstellung des Originaltexts –  
bereit zum Einbetten in ein Bild.

Documentation written by: Jose Luis Ocana (GitHub: [0xZorro](https://github.com/0xZorro))  
Last updated: April 2025
