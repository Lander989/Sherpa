# SHERPA
*Tactiele GPS: een navigatiesysteem voor blinden en slechtziende dat hen tijdens hun traject begeleidt aan de hand van een tactiele wijzer dat hen de weg toont.* 

🛠️ Built by ``Corbin Braekevelt`` & ``Lander Dumont`` & ``Roland Derynck``    
🔥 Supervised by ``prof. dr. Bas Baccarne``, ``Yannick Christiaens`` & ``Wouter Devriese``    
🌱 Grown at ``Ghent University`` 🏛️ ``Industrial Design Engineering`` ([project overview](https://github.com/basbaccarne/human-centered-design))       

*13/06/2026 van de laatste update*   

## Samenvatting
Personen met een visuele beperking ervaren vaak onzekerheid tijdens het navigeren. Huidige hulpmiddelen zoals spraak-GPS vragen veel concentratie (hoge cognitieve belasting), terwijl de gebruiker vooral behoefte heeft aan geruststelling en context op aangeleerde trajecten.

Ons onderzoek werd via het Triple Diamond-model uitgevoerd. Na veldonderzoek, interviews en testen bleek dat onze eerste poging, de tactiele kaart (wave 1) te complex was om te interpreteren tijdens het wandelen. Dit leidde tot een cruciale pivot naar *SHERPA*: een intuïtief navigatietoestel met een fysiek draaibare pijl, gebaseerd op het ‘Record & Replay’-principe.

**Record:** De gebruiker (of begeleider) wandelt een traject eenmalig af. Het toestel mapt automatisch de route. Herkenningspunten en obstakels worden via spraakberichten toegevoegd, waarna de route wordt opgeslagen in een persoonlijke keuzelijst.

**Replay:** De gebruiker selecteert een traject. De pijl, aangestuurd door de ingebouwde IMU en het kompas, wijst continu de juiste richting aan. Hierdoor vallen complexe instructies weg. Dit voelbare, constante oriëntatiepunt zorgt voor mentale rust en meer zelfvertrouwen, zonder onnodige afleidingen.

> *Om dit binnen de scope van het project te realiseren, werd er voor het finale prototype voor gekozen om uitsluitend de replay-fase integraal uit te werken aan de hand van de drie develop-fases.*

<p align="center">
  <img src="img\readme prototype foto.jpg" width="100%">
</p>

## Introductie

De snelle digitalisering van de samenleving biedt kansen, maar creëert ook het risico dat personen met een visuele beperking worden uitgesloten wanneer interfaces niet toegankelijk zijn (Abdelkhalek, 2019)[^1]. Hoewel er diverse navigatiehulpmiddelen bestaan, blijft autonome navigatie in een veranderlijke omgeving een grote opgave. Het continu verwerken van complexe omgevingsinformatie vergt vaak een extreem hoge cognitieve inspanning, wat leidt tot mentale vermoeidheid en onzekerheid bij de gebruiker (Brayda et al., 2018)[^2].

Het doel van dit project is de ontwikkeling van een intuïtief hulpmiddel dat blinde personen ondersteunt bij het aanleren en onderhouden van trajecten. De focus ligt hierbij niet louter op het bereiken van een bestemming, maar op het bieden van context en geruststelling tijdens de verplaatsing. Door de mentale belasting (cognitive load) te minimaliseren, willen we de autonomie en het zelfvertrouwen van de gebruiker vergroten, zodat zij zich veiliger voelen in de openbare ruimte.

Een cruciale randvoorwaarde is dat de oplossing functioneert als aanvulling op de witte stok, specifiek voor buitengebruik (outdoor navigation). Het ontwerp moet blindelings en met één hand bedienbaar zijn, zodat het gehoor vrij blijft en de fysieke veiligheid van de gebruiker te allen tijde gewaarborgd is.

## Inhoudstafel

1. [Methodologie](./docs/methodologie.md)
2. [Discovery](./docs/discovery.md)
3. [Defintion](./docs/definition.md)
4. [Develop](./docs/develop.md)
5. [Opkomende Technologie](./docs/Opkomende%20Technologieën.md)
6. [Bill of materials](./docs/bom.md)
7. [Design Requirements](./docs/design_requirements.md)
## Kritische reflectie

<p align="center">
  <img src="img/GIF render to wire.gif" width="100%">
</p>

##### Semester 1:

Als we terugkijken op het proces van het eerste semester, was de keuze om te pivoten van de tactiele matrix naar de pijl zonder twijfel het kantelpunt. We hebben in het begin veel tijd gestoken in het matrix-concept, om er tijdens de Think Aloud-testen achter te komen dat dit cognitief veel te zwaar was voor de gebruiker. Deze validatieslag was cruciaal om te beseffen dat de gebruiker eigenlijk geen kaart wil ontcijferen, maar vooral op zoek is naar geruststelling en eenvoudige richting.

Toch moeten we kritisch zijn op onze validatie in de laatste fase. De Wizard of Oz-methode in wave 2 was perfect om het gevoel van de pijl te testen, maar het verhult de technische realiteit. Omdat wij zelf de pijl bestuurden, hielden we geen rekening met factoren zoals GPS-signaalverlies of onnauwkeurigheid in een stedelijke omgeving. We hebben dus wel de gebruikerservaring (UX) gevalideerd, maar de technische haalbaarheid is een risico dat we doorschuiven naar het volgende semester.

Daarnaast is onze testgroep (N=4) vrij homogeen gebleven. Onze respondenten, zoals Pieter-Jan, zijn al erg zelfstandig en mobiel. Hierdoor bestaat het risico dat we een oplossing hebben ontworpen voor een ‘best-case scenario’. Het is voor ons een belangrijk werkpunt om in de toekomst te testen met mensen die onzekerder zijn in het verkeer, om te zien of het ‘Record & Replay’-concept hen ook voldoende vertrouwen biedt.
##### Semester 2 
De input van mensen uit de doelgroep kan niet onderschat worden. Op het einde van het project zijn we contact verloren met een paar mensen van onze doorgroep. Dit was zeer nadelig voor zowel onderzoek als het maken van designbeslissingen.

## Noot inzake het gebruik van AI
Binnen dit project is Gemini ingezet als ondersteunende AI-tool, met een strikt afgebakende rol:

* **Rapportage:** Het structureren van ruwe notities en het taalkundig verfijnen van teksten.
* **Development:** Ondersteuning bij het schrijven van de HTML-website.

> *AI werd nadrukkelijk niet ingezet voor inhoudelijke analyses of het bepalen van ontwerpbeslissingen en design requirements; deze fundamenten zijn uitsluitend gebaseerd op direct veldonderzoek en kritische teamreflectie.*


## Bijlagen
#### Discovery
* Literatuuronderzoek (N=16)

  [- Lander: Protocol literatuurstudie](<./reports and protocols/Protocol Literatuur Studie.pdf>)
  
  [- Roland: Protocol benchmarking](<./reports and protocols/Competitor analysis.pdf>)
  
  [- Corbin: Protocol benchmarking](<./reports and protocols/benchmarking_protocol_corbin_braekevelt.pdf>)
    
  [- Lander: Rapport literatuurstudie](<./reports and protocols/Rapport Literatuur Studie.pdf>)
  
  [- Roland: Rapport benchmarking](<./reports and protocols/Competitor analysis.pdf>)
  
  [- Corbin: Rapport benchmarking](<./reports and protocols/benchmarking_raport_corbin_braekevelt.pdf>)
* Interviews (N=12)

   [- Lander: Protocol interviews](<./reports and protocols/Protocol Interviews.pdf>)
  
   [- Roland: Protocol interviews](<./reports and protocols/Interviewprotocol_slechtzienden_!.pdf>)
  
   [- Corbin: Protocol interviews](<./reports and protocols/Interview-protocol-Corbin_Braekevelt.pdf>)

   [- Lander: Rapport interviews](<./reports and protocols/Rapport Interviews.pdf>)
  
   [- Roland: Rapport interviews](<./reports and protocols/Analyse respondenten rapport.pdf>)
  
   [- Corbin: Rapport interviews](<./reports and protocols/Interview-raport-Corbin_Braekevelt.pdf>)
    
#### Definition
* User testing wave 1 (N=6)
  * [Protocol](<./reports and protocols/Protocol Wave 1.pdf>)
  * [Rapport](<./reports and protocols/Verslag_wave1.pdf>)
* User testing wave 2 (N=2)
  * [Protocol](<./reports and protocols/Protocol Wave 2.pdf>)
  * [Rapport](<./reports and protocols/Rapport Wave 2.pdf>)

#### develop
* User testing develop 1 (N=5)
  * [protocol](<./reports and protocols/protocol_Deelopdracht 3 develop 1.pdf>)
  * [rapport](<./reports and protocols/Verslag_Deelopdracht 3 develop 1.pdf>)

* User testing develop 2 (N=5)
  * [protocol](<./reports and protocols/protocol_develop_2.pdf>)
  * [rapport](<./reports and protocols/Rapport_develop_2.pdf>)

* User testing develop 3 (N=2)
  * [protocol](<./reports and protocols/protocol_develop_3.pdf>)
  * [rapport](<./reports and protocols/Rapport_develop_3.pdf>)

## Licentie

This repository contains both software and design materials created as part of an industrial design energineering project at Ghent University.

- **Software and code:** [MIT License](./LICENSE-MIT)  
- **Design, documentation, CAD, and media:** [CC BY 4.0 License](./LICENSE)
  
You are free to reuse and build upon this work, both commercially and non-commercially, as long as proper attribution is given to the original authors.

## Bronnen
 [^1]:Abdelkhalek, M. (2019). Final Year Project Report - Blind Pad. University of Bath

 [^2]:Brayda, L. et al. (2018). Updated Tactile Feedback with a Pin Array Matrix. Micromachines, 9(7), 351

