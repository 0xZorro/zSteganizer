# Aufbau einer BMP-Datei und das Verstecken von Daten mit LSB-Steganografie

## Was ist eine BMP-Datei?

Eine BMP-Datei (Bitmap) ist ein einfaches, unkomprimiertes Bildformat, das vor allem für seine einfache Struktur bekannt ist.  
Da BMP-Dateien die Bildinformationen direkt abspeichern (Pixel für Pixel), eignet sich dieses Format ideal für Steganografie.

---

## Grundstruktur einer BMP-Datei

Eine klassische BMP-Datei besteht aus:

1. **Header (54 Bytes)**  
   Enthält Metadaten wie:
   - Dateityp (`BM`)
   - Dateigröße
   - Bildbreite & -höhe
   - Farbtiefe (z. B. 24 Bit pro Pixel)
   - Beginn der Pixeldaten

2. **Pixeldaten**  
   Die Farbinformationen für jedes Pixel – in der Regel im Format **BGR** (Blau-Grün-Rot), nicht RGB.

---

## Beispiel eines 24-Bit-BMP-Pixels

Ein einzelner Pixel hat 3 Bytes:

- 1 Byte für Blau
- 1 Byte für Grün
- 1 Byte für Rot

Ein Pixel in Binärform könnte z. B. so aussehen:
```
Blau: 11001010
Grün: 01101100
Rot: 10111101
```

---

## Was ist der „Least Significant Bit“ (LSB)?

Der **LSB** ist das **niederwertigste Bit** in einem Byte – also das ganz rechte Bit.

Beispiel:
```
Byte: 10111101
             ↑
           LSB
```

Wenn man dieses Bit ändert, ändert sich der Farbwert **nur minimal** – visuell ist das **nicht erkennbar**.  
Genau deshalb nutzen wir **LSB-Steganografie**.

---

## Wie versteckt man Daten in einem BMP?

1. Die Nachricht wird in eine Binärfolge umgewandelt
2. Diese Binärwerte (1 oder 0) werden in den LSB jedes Byte eines Pixels geschrieben
3. Dadurch ändern sich die Farben kaum, aber die Bits sind „versteckt“

Beispiel:

Original-Pixel:
```
Rot:   10111101
Grün:  01101100
Blau:  11001010
```

Nach dem Verstecken einer „1“ im Rot-Kanal:
```
Rot:   10111101 → bleibt gleich (LSB = 1)
```

Nach dem Verstecken einer „0“ im Grün-Kanal:
```
Grün:  01101100 → bleibt gleich (LSB = 0)
```

Nach dem Verstecken einer „1“ im Blau-Kanal:
```
Blau:  11001011 → LSB von 0 auf 1 geändert
```

---

## Warum funktioniert das so gut?

- Die Farbdifferenz durch 1 Bit ist **so gering**, dass sie mit dem menschlichen Auge **nicht wahrgenommen** wird
- Die Dateigröße bleibt **gleich**
- Die Daten lassen sich **präzise wiederherstellen**

---

## Zusammenfassung

BMP-Dateien sind ideal für LSB-Steganografie, weil sie:
- unkomprimiert sind
- einfach aufgebaut sind
- direkt auf die Pixeldaten zugreifen lassen

Mit LSB-Steganografie lassen sich **Texte, Codes oder sogar Dateien** unauffällig verstecken.


Documentation written by: Jose Luis Ocana (GitHub: [0xZorro](https://github.com/0xZorro))  
Last updated: April 2025