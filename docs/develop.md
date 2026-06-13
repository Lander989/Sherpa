
# Develop 1 (N = 5)

In deze eerste ontwikkelingsfase wordt het concept vertaald naar een functionele architectuur. Door het product op te splitsen in verschillende deelaspecten ontstaat meer inzicht in hoe het systeem zal werken en welke onderdelen nodig zijn. Daarnaast worden testen uitgevoerd met de doelgroep om de onderzoeksvragen, gebaseerd op de design requirements, te beantwoorden.

## Architectuur

Het systeem wordt opgesplitst in twee grote onderdelen: de **recordfase** en de **playfase**. Voor beide fases werd een Minimum Viable Product (MVP) gedefinieerd.

### Recordfase

* Het toestel kan een traject opnemen terwijl de gebruiker het traject aanleert.
* Het traject kan worden opgeslagen.

### Playfase

* De gebruiker kan een opgeslagen traject ophalen.
* Het toestel begeleidt de gebruiker doorheen het traject.

Onderstaand schema toont de verschillende fases en hun onderlinge relaties.

<p align="center">
  <img src="../img/systeemarchitectuur~~~user flow.png" width="100%">
</p>

## Onderzoeksvragen

De onderzoeksvragen dienen om de design requirements te vertalen naar concrete productspecificaties.

| Requirement                                                                                    | Onderzoeksvraag                                                                           |
| ---------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------- |
| **D3.1** Het systeem geeft continu de huidige looprichting tactiel weer.                       | Wat betekent de studie van Liu et al. (2021) voor het concept?                            |
| **D3.4** De gebruiker legt minder bekende trajecten af met zelfvertrouwen dankzij het systeem. | Wat is er nodig zodat het wijzerconcept voldoende zekerheid biedt aan de gebruiker?       |
| **D5.1** De UI is volledig bedienbaar zonder visuele informatie.                               | Welke elementen uit de systeemarchitectuur kunnen via trilsignalen worden gecommuniceerd? |

## Interactieve prototypes

De focus lag in deze fase op de verdere uitwerking van de wijzer. Vanuit het prototype uit de vorige fase werden zes varianten ontwikkeld. Na een interne evaluatie werden deze herwerkt en samengevoegd tot een testopstelling die werd aangestuurd met een RC-controller.

<p align="center">
  <img src="../img/overzicht prototypes.png" width="100%">
</p>

## User Testing

Voor de testen werden een protocol en een rapport opgesteld.

* [protocol](<../reports and protocols/protocol_Deelopdracht 3 develop 1.pdf>)
* [rapport](<../reports and protocols/Verslag_Deelopdracht 3 develop 1.pdf>)

### Doel van de testen

Drie deelonderzoeken werden uitgevoerd met vijf visueel beperkte respondenten, variërend van volledig blind tot personen met restvisus.

De onderzoeken hadden als doel om:

1. De duidelijkste vorm van tactiele richtingsaansturing te bepalen.
2. Het meest geschikte prototype te evalueren in een realistische wandelcontext.
3. De verstaanbaarheid van trilsignalen als feedbackmechanisme te onderzoeken.

# Test 1 – Cirkeltest

<div style="display: flex; gap: 10px; align-items: center;">
  <img src="../img/Mirjan_small.gif" style="height: 500; width: auto;" alt="Mirjan">
  <img src="../img/Cirkel_Test.jpg" style="height: 400; width: auto;" alt="Cirkel Test">
</div>

## Opzet

De proefpersonen stonden in het midden van een cirkel die was onderverdeeld in sectoren van 30°. Drie prototypes (driehoek, draaiwijzer en schijf met balk) werden draadloos aangestuurd. De gebruiker voelde de stand van de wijzer, draaide zich naar de vermeende richting en wees met een witte stok. De afwijking ten opzichte van de doelrichting werd geregistreerd.

## Resultaten

### Referentie en positie

Bij versie C trad een omgekeerd effect op. De pijl wees naar links, terwijl de testpersoon naar rechts draaide. Drie van de vijf testpersonen interpreteerden de stilstaande pijl als richtingaanwijzer en het draaiende element als referentie.

Mark, die nog over restvisus beschikt, scoorde goed met versie C. Dit was de enige versie met voldoende visueel contrast.

Bij versie B werden bewegend element en referentiepunt omgewisseld. Dit leverde geen interpretatieproblemen op.

Bij versie A ontbrak een vast referentiepunt, wat resulteerde in minder nauwkeurige positionering.

### Zelfzekerheid

Versie A gaf gebruikers het meeste vertrouwen, maar leidde tegelijk tot de meeste fouten. Een grotere pijl lijkt dus meer vertrouwen te creëren, ongeacht de daadwerkelijke nauwkeurigheid.

### Belangrijkste bevindingen

* Een referentiepunt is noodzakelijk.
* Het referentiepunt bevindt zich best achter de pijl.
* Een grotere pijl wordt duidelijker ervaren.
* Extra contrast verhoogt de bruikbaarheid voor slechtzienden.

### Evaluatie van de test

De cirkeltest leverde waardevolle inzichten op voor de leercurve en het gebruikersvertrouwen. De opstelling was echter niet nauwkeurig genoeg om harde uitspraken te doen over een richtingsnauwkeurigheid binnen 30°.

#### Beperkingen

* **Onderzoekersbias:** timing van metingen was niet altijd consistent.
* **Resolutie:** de positie van deelnemers kon niet altijd exact worden afgelezen.

# Test 2 – Trajectaanduiding

## Opzet

Met de twee best presterende prototypes (driehoek en draaiwijzer) werd een wandelparcours met rechte stukken en bochten afgelegd.

## Resultaten

### Resultaten

- **Driehoek (3/5 voorkeur):** functioneerde goed, maar er was behoefte aan een duidelijk referentiepunt. Dit werd tijdens de test tijdelijk opgelost met tape.
- **Draaiwijzer (2/5 voorkeur):** werd intuïtief gebruikt, maar het onderscheid tussen het draaiende deel en het referentiepunt moet duidelijker worden aangegeven.
- **Houding:** 3 van de 5 deelnemers hielden het prototype correct vast. Twee deelnemers hielden het toestel omgekeerd (met de pijl naar beneden gericht), wat wijst op de noodzaak van een meer ergonomische vormgeving.
- **Parkinson:** één respondent met Parkinson gebruikte haar wijsvinger om de pijl af te tasten in plaats van haar duim.
- **Richtingscorrecties:** kleine richtingsaanpassingen werden beter geïnterpreteerd dan grote richtingsveranderingen.

### Opmerking van een deelnemer

Tijdens een van de testen werd de volgende opmerking gemaakt:

> *"Kom maar eens mee naar het Citadelpark, dan vind ik misschien wel mijn weg terug."* — Chris

Deze uitspraak suggereert dat de deelnemer vertrouwen had in het toestel en de potentie ervan zag voor gebruik in een reële navigatiecontext.

# Test 3 – Vibratiefeedback

## Opzet

Tijdens de wandeling werden trilsignalen met vaste betekenissen aangeboden: start, herkenningspunt, waarschuwing en stop.

## Resultaten

* Lange trillingen voor start en stop werden correct geïnterpreteerd.
* Complexere patronen veroorzaakten verwarring en interpretatiefouten.

### Belangrijkste bevinding

Complexere signalen vereisen bijkomende verduidelijking of training.

## Nieuwe Design Requirements

| ID   | Design Requirement                                                                                                                 |
| ---- | ---------------------------------------------------------------------------------------------------------------------------------- |
| D5.6 | De tactiele richtingaanwijzer bevindt zich op een locatie die een neutrale en ontspannen polshouding toelaat tijdens het wandelen. |
| D3.5 | Het toestel is accuraat genoeg om de gebruiker op een veilig pad te houden en te begeleiden naar herkenningspunten.                |
| D3.2 | De gebruiker krijgt bevestiging wanneer hij correct georiënteerd is.                                                               |
| D3.3 | Het wijzersysteem bevat een duidelijk nulpunt of referentiepunt.                                                                   |
| D5.4 | De trilpatronen volgen de bestaande en vertrouwde tactiele semantiek van blindengeleidetegels.                                     |


## Develop 2 (N=2)

### Inleiding

In deze fase worden zowel de ergonomie van de controller onderzocht als de nodige knoppen en de plaats van deze knoppen op het product.
Aan de hand van voor onderzoek en het raadplegen van bestaande studies werden verschillende prototypes van het product gerealiseerd. Deze prototypes werden dan getest bij de doelgroep.

---
### Onderzoeksvragen

* Hoe maken we de interacties ergonomisch, met nadruk op een lage mentale belasting?
* Hoe kan de vorm van het product de houding van de gebruiker sturen?
* Welke knoppen zijn geschikt en bruikbaar voor de doelgroep?
* Wat is de beste plaatsing van die knopen op het product voor de doelgroep ?

---
### Vooronderzoek ergonomie// verloop
Om het verloop van deze fase lichter te maken, werden de ontwerpen van de prototypes gebaseerd op bestaande producten en onderzoek.
Als eerste stap werd er gekeken naar bestaande producten. Deze werden beschreven en bestudeerd in een benchmark.

Vervolgens werden de nodige inputs gemapt naar verschillende buttonlayouts. Daarna werd gekeken naar bestaande onderzoeken rond ergonomie, hoofdzakelijk met betrekking tot de hand. Kritische maten werden bepaald om vervolgens met een ontwerpstrategie de exacte afmetingen vast te leggen.

Als ondersteuning werden kleimodellen gemaakt om vormen en maten te valideren. Uiteindelijk resulteerde dit onderzoek in enkele prototypes om mee naar de doelgroep te trekken.

Alle bevindingen werden neergeschreven in een onderzoeksrapport, dat hier te lezen is.
* [rapport](<../>)



---
### Usertesting
De testen bestaan uit twee delen. Het eerste onderzoek kijkt naar hoe gebruikers spontaan omgaan met de prototypes. Daarnaast wordt hen gevraagd om de prototypes te rangschikken van meest comfortabel naar minst comfortabel, met bijhorende argumentatie.

<p align="center">
  <img src="../img/Dev_2_T1.jpg" width="75%">
</p>



Het tweede deel gaat in op het gebruik. Eén van de prototypes is verder uitgewerkt om de interacties na te bootsen. Hiermee wordt een scenario nagespeeld. Als onderzoeker observeren we welke handelingen de gebruikers stellen, bijvoorbeeld hoe ze het toestel wegsteken en hoe ze het vasthouden wanneer ze het niet gebruiken.

Voor de testen met de doelgroep werden een protocol en rapport geschreven. deze zijn hier te lezen. 
* [protocol](<../>)
* [rapport](<../>)


#### Doel van de testen

---
###  Bronnen
* Liu, G., Yu, T., Yu, C., Xu, H., Xu, S., Yang, C., Wang, F., Mi, H., & Shi, Y., Tactile Compass: Enabling Visually Impaired People to Follow a Path with Continuous Directional Feedback, CHI Conference on Human Factors in Computing Systems, 2021. https://doi.org/10.1145/3411764.3445644

* DJI RC Motion 3 - Motion Control, Easy ACRO - DJI United States. (n.d.). DJI. https://www.dji.com/be/rc-motion-3
* Genshin Impact Limited Edition DualSense Controller | PS5. (n.d.). [Video]. PlayStation. https://www.playstation.com/en-hk/accessories/dualsense-wireless-controller/
* Wikipedia contributors. (2026b, April 24). Wii Remote. Wikipedia. https://en.wikipedia.org/wiki/Wii_Remote

* González, A. G. (2018). An ergonomic customized-tool handle design for precision tools using additive manufacturing: A case study. Applied Sciences. Opgehaald van doi.org: https://doi.org/10.3390/app8071200

* Patkin's, M. (2026). A Check-List for Handle Design. (z.d.). Opgehaald van Michael Patkin's: https://mpatkin.org/ergonomics/handle_checklist.htm

* Tilley, A. R. (1974). Opgehaald van Whitney Library of Design: https://arc104201516.wordpress.com/wp-content/uploads/2016/02/the-measure-of-man-and-woman-human-factors-in-design-alvin-r-tilley-henry


