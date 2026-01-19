# Projecttitel
*Tactiele GPS: een navigatiesysteem voor blinden dat hen tijdens hun traject begeleidt aan de hand van tactiele snapshots van de omgeving.* 

🛠️ Built by ``Corbin Breakevelt`` & ``Lander Dumont`` & ``Roland Derynck``    
🔥 Supervised by ``prof. dr. Bas Baccarne``, ``Yannick Christiaens`` & ``Wouter Devriese``    
🌱 Grown at ``Ghent University`` 🏛️ ``Industrial Design Engineering`` ([project overview](https://github.com/basbaccarne/human-centered-design))       

*Dag/Maand/Jaar van de laatste update*   

## Samenvatting
In de eerste fase van dit project hebben we de wereld van blinden leren kennen. We bezochten een blindenbeurs en gingen in gesprek met mensen met een visuele beperking. Daarbij spraken we over uiteenlopende onderwerpen en verzamelden we veel inzichten.

Een van de belangrijkste observaties die we deden, is de manier waarop blinden zich verplaatsen. We merkten dat zij vaak afhankelijk zijn van aangeleerde trajecten. Deze routes leren zij stap voor stap aan, en na voldoende training kunnen ze deze zelfstandig afleggen.

Hierop wilden wij inspelen door een oplossing te ontwikkelen die hen hierin ondersteunt. Dit doen we aan de hand van een tactiele GPS. Met behulp van een braillescherm of pin-matrix kunnen blinden een tactiele ‘snapshot’ van hun omgeving voelen. Op die manier kunnen zij de omgeving op een voelbare manier begrijpen. Waar conventionele hulpmiddelen vaak enkel gefocust zijn op de exacte route, biedt dit hulpmiddel een breder beeld van de omgeving.

<p align="center">
  <img src="img/Tactile GPS.jpg" width="100%">
</p>

## Introductie

De snelle digitalisering van de samenleving biedt kansen, maar creëert ook het risico dat personen met een visuele beperking worden uitgesloten wanneer interfaces niet toegankelijk zijn (Abdelkhalek, 2019)[^1]. Hoewel er diverse navigatiehulpmiddelen bestaan, blijft autonome navigatie in een veranderlijke omgeving een grote opgave. Het continu verwerken van complexe omgevingsinformatie vergt vaak een extreem hoge cognitieve inspanning, wat leidt tot mentale vermoeidheid en onzekerheid bij de gebruiker (Brayda et al., 2018)[^2].

Het doel van dit project is de ontwikkeling van een intuïtief hulpmiddel dat blinde personen ondersteunt bij het aanleren en onderhouden van trajecten. De focus ligt hierbij niet louter op het bereiken van een bestemming, maar op het bieden van context en geruststelling tijdens de verplaatsing. Door de mentale belasting (cognitive load) te minimaliseren, willen we de autonomie en het zelfvertrouwen van de gebruiker vergroten, zodat zij zich veiliger voelen in de openbare ruimte.

Een cruciale randvoorwaarde is dat de oplossing functioneert als aanvulling op de witte stok, specifiek voor buitengebruik (outdoor navigation). Het ontwerp moet blindelings en met één hand bedienbaar zijn, zodat het gehoor vrij blijft en de fysieke veiligheid van de gebruiker te allen tijde gewaarborgd is.

## Inhoudstafel

1. [Methodologie](./docs/methodologie.md)
2. [Discovery](./docs/discovery.md)
3. [Defintion](./docs/definition.md)
4. [Design Requirements](./docs/design_requirements.md)
5. [Bill of materials](./docs/bom.md)

## Kritische reflectie
Semester 1:

Als we terugkijken op het proces van het eerste semester, was de keuze om te pivoten van de tactiele matrix naar de pijl zonder twijfel het kantelpunt. We hebben in het begin veel tijd gestoken in het matrix-concept, om er tijdens de Think Aloud-testen achter te komen dat dit cognitief veel te zwaar was voor de gebruiker. Deze validatieslag was cruciaal om te beseffen dat de gebruiker eigenlijk geen kaart wil ontcijferen, maar vooral op zoek is naar geruststelling en eenvoudige richting.

Toch moeten we kritisch zijn op onze validatie in de laatste fase. De Wizard of Oz-methode in Wave 2 was perfect om het gevoel van de pijl te testen, maar het verhult de technische realiteit. Omdat wij zelf de pijl bestuurden, hielden we geen rekening met factoren zoals GPS-signaalverlies of onnauwkeurigheid in een stedelijke omgeving. We hebben dus wel de gebruikerservaring (UX) gevalideerd, maar de technische haalbaarheid is een risico dat we doorschuiven naar het volgende semester.

Daarnaast is onze testgroep (N=4) vrij homogeen gebleven. Onze respondenten, zoals Pieter-Jan, zijn al erg zelfstandig en mobiel. Hierdoor bestaat het risico dat we een oplossing hebben ontworpen voor een ‘best-case scenario’. Het is voor ons een belangrijk werkpunt om in de toekomst te testen met mensen die onzekerder zijn in het verkeer, om te zien of het ‘Record & Replay’-concept hen ook voldoende vertrouwen biedt.


## Noot inzake het gebruik van AI
In semester 1 maakte Roland gebruik van AI. Hij zette Whisper in om audiobestanden te transcriberen en ChatGPT voor de analyse. Gemini en chatgpt werden gebruikt om de documentatie in github in te korten en vlotter te maken. Corbin gebruikte geen AI, zowel voor de documentatie als het project.

## Bijlagen
### Discovery
* Literatuuronderzoek (N=16)

  [- Lander: Protocol literatuurstudie](<./reports and protocols/Protocol Literatuur Studie.pdf>)
  
  [- Roland: Protocol benchmarking](<./>)
  
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
    
### Definition
* User testing wave 1 (N=6)
  * [Protocol](<./reports and protocols/Protocol Wave 1.pdf>)
  * [Rapport](<./reports and protocols/Verslag_wave1.pdf>)
* User testing wave 2 (N=2)
  * [Protocol](<./reports and protocols/Protocol Wave 2.pdf>)
  * [Rapport](<./reports and protocols/Rapport Wave 2.pdf>)

## Licentie

This repository contains both software and design materials created as part of an industrial design energineering project at Ghent University.

- **Software and code:** [MIT License](./LICENSE-MIT)  
- **Design, documentation, CAD, and media:** [CC BY 4.0 License](./LICENSE)
  
You are free to reuse and build upon this work, both commercially and non-commercially, as long as proper attribution is given to the original authors.

## Bronnen
 [^1]:Abdelkhalek, M. (2019). Final Year Project Report - Blind Pad. University of Bath

 [^2]:Brayda, L. et al. (2018). Updated Tactile Feedback with a Pin Array Matrix. Micromachines, 9(7), 351

