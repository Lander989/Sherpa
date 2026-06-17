# SHERPA — Product Design Requirements


Elke requirement is opgesteld in de vorm 'Het systeem / De gebruiker [doet X]' en bevat een concreet meetcriterium met een pass/fail-grens. De prioriteit volgt de MoSCoW-methode. Het meettype geeft aan of getoetst wordt via directe observatie (Observed) of via bevraagde beleving (Perceived).

---

## 1 Gebruikers kunnen een traject zelfstandig afleggen zonder hulp van derden

| Nr. | Bron | Requirement | Meetcriterium (pass/fail) | Priority | Meting |
|-----|------|-------------|--------------------------|----------|--------|
| 1.1 | Develop 1 | Het systeem begeleidt de gebruiker doorheen een traject zodat elk herkenningspunt aantoonbaar bereikt wordt. | ≥ 100% van de herkenningspunten correct bereikt tijdens usability test (observatie per punt: ja/nee). | Must have | Observed |
| 1.2 | Definition wave 2 | Het systeem geeft eenduidige feedback bij correcte richting, foute richting, herkenningspunten en gevaarlijke locaties. | Deelnemer reageert correct (stopt, keert, bevestigt) op elk feedbacksignaal; ≥ 90% correcte reacties per sessie. | Must have | Observed |
| 1.3 | Definition wave 2 | De gebruiker toont geen verwarring bij de start van het traject. | Geen observeerbare verwarring (pauze > 10 s, foutieve richting, verbale twijfel) in de eerste 60 s; getoetst bij ≥ 4 van 5 deelnemers. | Should have | Observed |

---

## 2 Gebruikers kunnen met hulp van derden trajecten opnemen

| Nr. | Bron | Requirement | Meetcriterium (pass/fail) | Priority | Meting |
|-----|------|-------------|--------------------------|----------|--------|
| 2.1 | Definition wave 2 | De gebruiker kan met hulp van de begeleider persoonlijke herkenningspunten aanmaken. | Het duo slaagt erin om een herkenningspunt succesvol aan te maken; Ja/Nee. | Should have | Observed |
| 2.2 | Develop 2 | Een begeleider kan zonder technische voorkennis een traject aanmaken. | Opnametijd gemeten bij 2 begeleiders; beide trajecten klaar in ≤ 15 min. | Should have | Observed |
| 2.3 | Develop 2 | De begeleider ervaart het opnameproces als eenvoudig. | Likert 1–7 'Het opnemen van het traject was eenvoudig.' ≥ 5/7. | Could have | Perceived |

---

## 3 Gebruikers ervaren continu oriëntatie en vertrouwen tijdens het gebruik

| Nr. | Bron | Requirement | Meetcriterium (pass/fail) | Priority | Meting |
|-----|------|-------------|--------------------------|----------|--------|
| 3.1 | Definition wave 2 | Het systeem geeft continu de huidige looprichting visueel of tactiel weer. | Wijzer reageert op richtingsverandering van ≥ 15° binnen 0,5 s; getoetst via QAP-meting. | Must have | Observed |
| 3.2 | Develop 1 | De gebruiker ontvangt bevestiging (trilpatroon of wijzerpositie) wanneer hij correct georiënteerd staat. | Deelnemer herkent het bevestigingssignaal correct bij ≥ 4 van 5 pogingen (evaluatieblad). | Should have | Observed |
| 3.3 | Develop 1 | Het wijzersysteem heeft een duidelijk voelbaar nulpunt dat de neutrale (correcte) richting aangeeft. | Deelnemer wijst de richting aan binnen de sectoren van 30° bij ≥ 4 van 5 metingen (cirkeltest, sectordiagram). | Must have | Observed |
| 3.4 | Definition wave 2 | De gebruiker legt minder bekende trajecten af met zelfvertrouwen dankzij het systeem. | Likert 1–7 'Ik had er vertrouwen in dat ik de bestemming zou bereiken.' ≥ 5/7 gemiddeld. | Must have | Perceived |

---

## 4 Gebruikers blijven fysiek veilig tijdens navigatie

| Nr. | Bron | Requirement | Meetcriterium (pass/fail) | Priority | Meting |
|-----|------|-------------|--------------------------|----------|--------|
| 4.1 | Definition 1 | Het gebruik van de witte stok wordt niet belemmerd door het product. | Deelnemer raakt geen obstakel dat door de stok gedetecteerd had moeten worden; 0 obstakelcontacten bij ≥ 3 deelnemers tijdens trajecttest. | Must have | Observed |
| 4.2 | Definition 1 | Het product is volledig bedienbaar met één hand. | Alle interacties (opstart, navigatie, stop) worden uitgevoerd met één hand; 0 gevallen waarbij tweede hand nodig was (observatie). | Should have | Observed |
| 4.3 | Definition 1 | Het systeem geeft duidelijke feedback bij gevaarlijke locaties (zebrapad, open ruimte, tunnel). | Correct feedbacksignaal wordt gegeven op alle vooraf gedefinieerde gevaarlijke punten in het testparcours. | Must have | Observed |
| 4.4 | Evaluatie burgerlijk ing. | Het systeem detecteert wanneer GPS-signaal of sensorkoppeling wegvalt en signaleert dit aan de gebruiker. | Bij signaalverlies geeft het toestel direct een foutmelding (audio of trilpatroon). | Should have | Observed |
| 4.5 | Develop 1 | De gebruiker krijgt bevestigende feedback dat het systeem actief en correct werkt bij opstart. | Bevestigingssignaal (tril of audio) hoorbaar/voelbaar; herkend door ≥ 4 van 5 deelnemers. | Should have | Observed |
| 4.6 | Develop 1 | Het systeem houdt de gebruiker op een veilig pad met een nauwkeurigheid van ≤ 60 cm afwijking. | Steps-in-Zone (SIZ) ≥ 90% op een pad van 60 cm breedte; gemeten via video-observatie (identieke methode Develop 1/2). | Must have | Observed |
| 4.7 | Develop 2 | De batterijlevensduur is voldoende voor minstens 4 uur actief gebruik. | Toestel blijft actief gedurende een gesimuleerde sessie van 2 uur zonder laadonderbreking; getoetst via technische duurtest. | Must have | Observed |

---

## 5 Het systeem vereist minimale training en mentale en fysieke inspanning

| Nr. | Bron | Requirement | Meetcriterium (pass/fail) | Priority | Meting |
|-----|------|-------------|--------------------------|----------|--------|
| 5.1 | Discovery | De UI is volledig bedienbaar zonder visuele informatie (geschikt voor blinden en slechtzienden). | Blinde deelnemers voltooien alle UI-taken (opstart, trajectkeuze, stop) zonder blokkering bij ≥ 4 van 5 deelnemers. | Must have | Observed |
| 5.2 | Definition wave 1 | De bedieningsknoppen zijn tactiel onderscheidbaar (voelbare rand, hoogteverschil, index). | Deelnemer identificeert elke knop correct op gevoel zonder uitleg; ≥ 4 van 5 deelnemers slagen bij eerste aanraking. | Should have | Observed |
| 5.3 | Develop 1 | Trilsignalen bevatten maximaal 3 onderscheidbare patronen en brengen geen complexe data over. | Elk trilpatroon wordt door ≥ 100% van de deelnemers correct geïnterpreteerd; max. 3 patronen gedefinieerd in het systeem. | Must have | Observed |
| 5.4 | Develop 1 | Trilpatronen sluiten aan bij vertrouwde tactiele semantiek van blindengeleidetegels (kort=stop, lang=ga). | Likert 1–7 'De trilpatronen voelden vertrouwd aan.' ≥ 4,5/7 gemiddeld. | Should have | Perceived |
| 5.5 | Definition wave 1 | Het systeem is bruikbaar na een enkele uitlegsessie van ≤ 20 minuten. | Na een introductiefase van max. 20 min voltooit de deelnemer het testparcours met ≤ 2 begeleidersinterventies. | Should have | Observed |
| 5.6 | Develop 1 | De tactiele richtingaanwijzer bevindt zich op een positie die een neutrale, ontspannen polshouding toelaat. | ≥ 3 van 5 deelnemers nemen direct een neutrale polshouding aan bij eerste aanraking (observatie, geen aanwijzing). | Should have | Observed |
| 5.7 | Develop 2 | Het toestel past in een broekzak. | ≥ 4 van 5 deelnemers steekt het toestel zonder problemen weg. | Could have | Observed |
| 5.8 | Develop 1 | Het systeem ondersteunt elke essentiële stap (opstart, trajectkeuze, navigatie, herkenningspunt, stop) met gesproken instructie. | Alle essentiële stappen worden door het systeem ondersteund met gesproken instructie; gecontroleerd via walkthrough van het volledige parcours. | Must have | Observed |
| 5.9 | Develop 2 | De gebruiker heeft vertrouwen dat het toestel niet uit de hand kan vallen tijdens gebruik. | Minstens 90% van de gebruikers rapporteert een gevoel van zekerheid tijdens het vasthouden én geen enkele gebruiker laat het toestel vallen tijdens de gebruikstest. | Should have | Observed / Perceived |



---

## Legende

| Term | Betekenis |
|------|-----------|
| **Must have** | Kritieke vereiste; product faalt als dit niet gehaald wordt. |
| **Should have** | Belangrijke vereiste; sterk aanbevolen maar niet blokkerend. |
| **Could have** | Wenselijke extra; enkel als tijd en budget het toelaten. |
| **Observed** | Getoetst via directe observatie of video-analyse tijdens de test. |
| **Perceived** | Getoetst via Likert-schaal of gestructureerde bevraging na de test. |

> **Nummering:** is niet chronologisch, maar geplaatst bij de bijhorende productdoelstelling.