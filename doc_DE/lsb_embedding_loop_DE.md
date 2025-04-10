# Einbetten von Bits in BMP-Pixel mithilfe des Least Significant Bit (LSB)

Dieses Dokument erklärt einen zentralen Teil des Projekts `zSteganizer`:  
Wie eine binäre Nachricht in ein BMP-Bild eingebettet wird – durch Bitoperationen auf Pixeldaten.  
Im Fokus steht eine Schleife, die gezielt das niederwertigste Bit (LSB) jedes Bytes manipuliert.

---

## Code-Segment

```cpp
while (inFile.get(pixel)) {
    // Modify least significant bit of each byte to embed the message bit
    if (bitIndex < binaryMessage.size()) {
        pixel = (pixel & ~1) | (binaryMessage[bitIndex] - '0');
        bitIndex++;
    }
    // Write pixel to output
    outFile.put(pixel);
}
```

---

## Zeile-für-Zeile-Erklärung

```cpp
while (inFile.get(pixel)) {
```
Liest jeweils ein Byte (`pixel`) aus der BMP-Datei ein.  
Die Schleife läuft, bis das Dateiende erreicht ist.

```cpp
if (bitIndex < binaryMessage.size()) {
```
Prüft, ob noch Bits in der Binärnachricht vorhanden sind, die eingebettet werden müssen.  
Wenn nicht, wird das Byte unverändert weitergeschrieben.

```cpp
pixel = (pixel & ~1) | (binaryMessage[bitIndex] - '0');
```
Hier passiert die gezielte Bitmanipulation:

- `pixel & ~1` bitweises UND mit der bitweise negation (~1) 
 
Beispiel: pixel:   10111101
          ~1:      11111110
          ----------------
          ERGEBNIS:10111100

- `binaryMessage[bitIndex] - '0'` wandelt das Zeichen ('0' oder '1') in den Zahlenwert 0 oder 1 um
- `|` schreibt diesen Wert ins LSB (OR-Verknüpfung)

Beispiel:  
Wenn `pixel = 10111101` und Bit der Nachricht = 0  
→ `pixel & ~1` → `10111100`   // ~1 = bitweise Negation (NOT): 00000001 =  11111110
→ `| 0` → bleibt `10111100`  
→ Ergebnis: LSB enthält jetzt die Bitinformation

```cpp
bitIndex++;
```
Springt zum nächsten Bit in der Nachricht.

```cpp
outFile.put(pixel);
```
Schreibt das modifizierte (oder originale) Byte in die Ausgabedatei.

---

## Zusammenfassung

In jeder Iteration wird genau ein Bit der Nachricht im LSB eines Bildbytes versteckt.  
Diese minimale Änderung bleibt für das menschliche Auge unsichtbar, speichert aber zuverlässig die Daten.



Documentation written by: Jose Luis Ocana (GitHub: [0xZorro](https://github.com/0xZorro))  
Last updated: April 2025
