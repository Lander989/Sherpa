# Develop

## Develop 1 (N=5)

In deze eerste ontwikkelingsfase wordt het concept vertaald naar een functionele architectuur. Door het product op te splitsen in verschillende deelaspecten ontstaat meer inzicht in hoe het systeem zal werken en welke onderdelen nodig zijn. Daarnaast worden er testen uitgevoerd samen met de doelgroep om de onderzoeksvragen op basis van de requierments te beantwoorden.

---

### Architectuur

Het systeem wordt opgesplitst in twee grote onderdelen: de recordfase en de playfase. Voor beide fases werd een MVP gedefinieerd.
#### Recordfase

* Het toestel kan een traject opnemen terwijl de gebruiker het traject aanleert.

* Het traject kan op een bepaalde manier worden opgeslagen.

#### Playfase

* De gebruiker kan een opgeslagen traject ophalen.

* Het toestel begeleidt de gebruiker doorheen het traject.

In het schema worden de verschillende fases en mogelijke manieren waarop deze kunnen werken in kaart gebracht. 

<p align="center">
  <img src="../img/systeemarchitectuur~~~user flow.png" width="100%">
</p>

---

### Onderzoeksvragen

D3.1 Het systeem geeft continu de huidige looprichting tactiel weer.

* Wat  betekend de studie van Liu et al. (2021) voor het concept?

D3.4 De gebruiker legt minder bekende trajecten af met zelfvertrouwen dankzij het systeem.
* Wat is er nodig zodat het wijzerconcept zekerheid biedt aan de gebruiker?

D5.1 De UI is volledig bedienbaar zonder visuele informatie (geschikt voor blinden en slechtzienden).
* Welke feedback uit de systeemarchitectuur kunnen via trilsignalen overgebracht worden?

---

### Interactive prototypen

De focus lag in deze fase bij het uitwerken van de wijzer. Hierbij werd vertrokken van het prototype uit de vorige fase. Daaruit ontstonden zes verschillende varianten. Deze werden eerst intern geëvalueerd en vervolgens herwerkt en samengevoegd in een testopstelling waarmee we naar onze doelgroep trokken. Deze opstelling wordt gestuurd aan de hand van een RC-controller.


<p align="center">
  <img src="../img/overzicht prototypes.png" width="100%">
</p>

---
### User testing

Voor de testen werd een protocol en rapport opgesteld. Deze zijn hier te lezen.
* [protocol](<../reports and protocols/protocol_Deelopdracht 3 develop 1.pdf>)
* [rapport](<../reports and protocols/Verslag_Deelopdracht 3 develop 1.pdf>)
### Doel van de testen
Drie deelonderzoeken werden uitgevoerd met vijf visueel beperkte respondenten (variërend van volledig blind tot restvisus) om:

* De duidelijkste manier van tactiele richtingsaansturing te bepalen (cirkeltest).

* Het beste prototype te testen in een realistische wandelcontext (trajectaanduiding).

* De verstaanbaarheid van trilsignalen als feedback te evalueren.



### Test 1 – Cirkeltest (richtingsnauwkeurigheid)

<div style="display: flex; gap: 10px; align-items: center;">
  <img src="../img/Mirjan_small.gif" style="height: 500; width: auto;" alt="Mirjan">
  <img src="../img/Cirkel_Test.jpg" style="height: 400; width: auto;" alt="Cirkel Test">
</div>




#### Opzet
Proefpersonen stonden in het midden van een cirkel (ingedeeld in sectoren van 30°). Drie prototypes (driehoek, draaiwijzer, schijf met balk) werden draadloos aangestuurd. De gebruiker voelde de stand, draaide zich naar de vermeende richting en wees met een witte stok. De afwijking werd geregistreerd.

#### Resultaten
*  De test was waardevol voor inzicht in leercurve en gebruiksgemak, maar te onnauwkeurig voor harde conclusies binnen een marge van 30°.
*  Er was geen eenduidige winnaar: de voorkeuren waren sterk individueel bepaald.
*  De testpersonen overcompenseerden hun kijkrichting wanneer de pijl van richting veranderde stilstond. De pijl die terugkeert naar 0 bij een correcte richting wordt verkeerd geïnterpreteerd.



### Test 2 – Trajectaanduiding (wandeltest)
#### Opzet
Met de beste prototypes (driehoek en draaiwijzer) werd een wandelparcours met bochten en rechte stukken afgelegd. Observaties richtten zich op interactie, verstaanbaarheid, bochtengedrag en zelfzekerheid.
#### Resultaten

* Driehoek (3/5 voorkeur): functioneerde goed, maar er was behoefte aan een duidelijk referentiepunt (tijdelijk opgelost met tape).

* Draaiwijzer (2/5 voorkeur): werd intuïtief gebruikt, maar het verschil tussen het draaiend deel en het referentiepunt moet duidelijker worden aangegeven.

* Houding: 3/5 hielden het prototype correct vast; twee hielden het omgekeerd (pijl naar de grond), wat wijst op nood aan een ergonomische vormgeving.

* Eén respondent met Parkinson gebruikte haar wijsvinger om de pijl af te tasten in plaats van de duim.

* Kleine bijsturingen werden beter geïnterpreteerd dan grote.


Tijdens een van de testen werd volgende opmerking gegeven:
>Chris: "Kom maar eens mee naar het Citadelpark, dan vind ik Misschien wel mijn weg terug".

Wat aantoont dat de persoon vertrouwen heeft in het toestel.


### Test 3 – Vibratiefeedback
#### Opzet
Tijdens de wandeling werden trilsignalen gegeven met vaste betekenissen (start, herkenningspunt, waarschuwing, stop). Reactietijd en interpretatiefouten werden genoteerd.
#### Resultaten
•	Eenvoudige signalen (lange trilling voor start/stop) werden goed begrepen.

•	Complexere patronen (zoals aantal pulsen) zorgden voor verwarring en fouten.

---
### Design requirements


ID   |                                                                                                                      | Fase       |
|------|--------------------------------------------------------------------------------------------------------------------------|------------|
| 2.11 | De tactiele richtingaanwijzer bevindt zich op een locatie die een neutrale, ontspannen polshouding toelaat tijdens het wandelen | Develop 1  |
| 3.5  | Het toestel is accuraat genoeg om de gebruiker op een veilig pad te houden en te begeleiden naar herkenningspunten       | Develop 1  |
| 1.7  | De gebruiker moet bevestiging krijgen wanneer hij correct georiënteerd is                                                | Develop 1  |
| 4.2  | Het wijzersysteem bevat een duidelijk nulpunt of referentie                                                             | Develop 1  |
| 4.3  | De trilpatronen volgen de bestaande en vertrouwde tactiele semantiek van blindengeleidetegels                          | Develop 1  |

--- 


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


