<p align="center">
  <img src="Banner.png" alt="zSteganizer" width="300"/>
</p>

<p align="right">
  <a href="./README_EN.md">Switch to English version</a>
</p>

# zSteganizer

**zSteganizer** ist ein C++-Tool zur Einbettung und Extraktion geheimer Textnachrichten in BMP-Bildern.  
Dabei kommt das Verfahren der **Least Significant Bit (LSB) Steganografie** zum Einsatz. Die Besonderheit:  
Nachrichten können so in Bildern versteckt werden, dass sie **für das menschliche Auge unsichtbar bleiben**.

---

## Was ist Steganografie?

Steganografie ist die Kunst, Informationen **unsichtbar** in Dateien wie Bildern, Audios oder Videos zu verstecken.  
Im Gegensatz zur Verschlüsselung, bei der der Inhalt geschützt wird, bleibt bei der Steganografie die Existenz der Nachricht **unsichtbar**.  
LSB-Steganografie ist eine Technik, bei der man das **niederwertigste Bit (LSB)** eines Farbwerts verändert, um Daten einzubetten.

---

## Funktionen

- Verstecken von Textnachrichten in 24-Bit BMP-Bildern
- Extraktion von versteckten Nachrichten aus BMP-Dateien
- Klar strukturierter und verständlicher C++-Code
- Bedienung über die Kommandozeile

---

## Motivation

Das Projekt wurde als praktische Übung zur **Datenverarbeitung auf Byte-Ebene** und zur **Steganografie** entwickelt.  
Es soll zeigen, wie man Dateien manipulieren und dabei Informationen in digitalen Medien unauffällig speichern kann.  
Der Fokus liegt auf Einfachheit, Funktionalität und Lernzwecken.

---

## Voraussetzungen

- Visual Studio 2022 (oder ein anderer C++17-kompatibler Compiler)
- Windows-Betriebssystem empfohlen (aber portierbar)
- Eine 24-Bit BMP-Datei als Eingabe

---

## Installation & Kompilierung

1. Erstelle ein neues C++-Projekt in **Visual Studio 2022** (leeres Konsolenprojekt).
2. Ersetze die automatisch generierte `.cpp`-Datei durch die Datei `zSteganizer.cpp`.
3. Stelle sicher, dass das Projekt im **Release-Modus** oder **Debug-Modus** kompiliert wird.
4. Baue das Projekt und starte die `.exe` über die Eingabeaufforderung.

---

## Verwendung

### Text in Bild einbetten:

```bash
zSteganizer embed -i eingabe.bmp -m nachricht.txt -o ausgabe.bmp
```

- `-i` : Originalbild (24-Bit BMP)
- `-m` : Textdatei mit der Nachricht
- `-o` : Zieldatei mit eingebetteter Nachricht

### Nachricht aus Bild extrahieren:

```bash
zSteganizer extract -i ausgabe.bmp -o result.txt
```

- `-i` : Bild mit versteckter Nachricht
- `-o` : Zieltextdatei für die extrahierte Nachricht


### Dokumentation

- [Deutsche Dokumentation ansehen (Least Significant Bit) ](./doc_DE/bmp_lsb_doc_DE.md)
- [Deutsche Dokumentation ansehen (Daten extrahieren) ](./doc_DE/extract_message_DE.md)
- [Deutsche Dokumentation ansehen (Schleife zum Einbetten von Daten) ](./doc_DE/lsb_embedding_loop_DE.md)
- [Deutsche Dokumentation ansehen (in Binärzeichenkette umwandeln) ](./doc_DE/to_binary_string_DE.md)


---

## Zukünftige Erweiterungen (Ideen)

- Unterstützung weiterer Bildformate (z. B. PNG mit Bibliotheken)
- Verschlüsselung der Nachricht vor Einbettung
- Grafische Benutzeroberfläche (GUI) für Drag-and-Drop
- Prüfung, ob die Nachricht in das Bild passt **vor** dem Schreiben
- Logging und Fortschrittsanzeige

---

## Lizenz

Dieses Projekt steht unter der MIT-Lizenz – siehe [LICENSE](LICENSE)-Datei für Details.

---

## Autor

**Created by Jose Luis Ocana**

Cybersecurity Learner | Python & C++ Tools

(GitHub: [0xZorro](https://github.com/0xZorro))  

TryHackMe: https://tryhackme.com/p/0xZorro

Contact: zorro.jose@gmx.de

---

## Beiträge

Du möchtest mithelfen? Super! Forke das Projekt, nimm Änderungen vor und stelle einen Pull Request.  
Achte bitte darauf, den Verhaltenskodex und die Projektstandards einzuhalten.

---

## Hinweis

Dieses Tool wurde **zu Lernzwecken** entwickelt.  
Bitte nutze es **nur auf Bildern und Texten, die du selbst besitzt oder verwenden darfst**.  
Der Autor übernimmt **keine Verantwortung** für eventuellen Missbrauch.

---

## Haftungsausschluss

Der Autor übernimmt **keinerlei Verantwortung oder Haftung** für Schäden, Missbrauch oder rechtliche Konsequenzen, die aus der Nutzung dieses Programms entstehen.

Die Verwendung erfolgt **auf eigene Verantwortung**.

---

<div align="center">
  <img src="brand.png" alt="by 0xZorro" width="120"/>
  <br/>
  <sub>© 2025 0xZorro</sub>
</div>

---
