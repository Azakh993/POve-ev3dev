# Introduktion

## Dokumentets syfte
Detta dokuments syfte är att stötta Projektgrupp 10 i genomförandet av projektet, dels genom att skapa en gemensam bas för medlemmarna, dels genom att ge en överblick över projektet.

## Dokumentets omfattning
Detta dokument behandlar följande:
  * Målsättningar associerade till projektet, dess omfattning och hur projektet skall realiseras.
Detta dokument behandlar inte följande:
  * Detaljer relaterade till programmering och konstruktion av LEGO-robot.

# Organisation

## Projektdeltagare

| Person                | Roll          | Kontaktinfo.   |
|-----------------------|---------------|----------------|
| Azmeer Akhtar Khawaja | Projektledare | aaak@kth.se    |
| Axel Lystam           | Projektmedlem | lystam@kth.se  |
| Daniel Dahlberg       | Projektmedlem | ddahlb@kth.se  |
| Marcus Cangren        | Projektmedlem | cangren@kth.se |
| Kursansvarig          | Uppgiftsägare |                |

## Kommunikation
Projektgruppen har Discord som primär kommunikationskanal. Förväntad responstid är inom en dag. För mer brådskande ärenden används SMS, och svar förväntas inom ett par timmar. Vid mer brådskande situationer används telefonsamtal.

## Mötesstruktur
### Mötestyper
Tre typer av mötesstrukturer används: informationsmöten, problemlösande möten samt beslutsmöten. Informationsmötens primära fokus är att förmedla information till varandra i teamet; problemlösande möten fokuserar på att adressera en eller flera punkter som teammedlemmarna inte kan lösa själva; beslutsmöten ämnar besluta om saker som omfattar mer än enskilda teammedlemmars ansvarsområden.

### Mötesstruktur
Varje vecka inleds och avslutas med ett informationsmöte; den första ämnar tydliggöra veckans fokus, medan den sista har som syfte att informera om översiktsstatus. I samband med veckoslut hålls även ett reflektionsseminarium vars syfte är att utvärdera veckans arbetsmetodik och därefter etablera vad som kan göras för att utveckla metodiken under nästkommande vecka. Problemlösande och beslutsmöten bokas enligt behov.

### Mötesbokning
Mötesbokning utfös enligt överenskommelse mellan samtliga teammedlemmar. Google Calendar används som kalenderplattform, och anger dag, tid, plats samt anteckningar av relevans för mötet.

## Arbetsplats
Individuellt arbete sker på valfri plats. Gruppsessioner och möten hålls primärt i grupprum i Elektrum (vilket specifikt rum som gäller specificeras i associerad kalenderevent), och sekundärt via Zoom i ett etablerat grupprum. Vid de tillfällen som en av teammedlemmarna inte kan närvara fysiskt, så används Zoom för deltagande.

## Arbetsutrustning
Av Uppdragsgivaren har projektgruppen fått LEGO-satsen ”LEGO MINDSTORMS Core Set, nr 45544” som används för fysiska konstruktionen av roboten. Samtliga projektmedlemmar använder egna datorer för digitalt arbete.

Följande mjukvaror och webbsidor används av projektgruppen:
  * Microsoft365: filhantering
    * Microsoft Excel: tidsrapportering
  * Microsoft OneDrive: fillagring och backup
  * Google Calendar: arbetsplanering/mötesbokning
  * JIRA: Work Breakdown Structure (WBS)

# Projektets tre huvudmål

## Resultatmål
Projektets deadline är 2021-10-13 och senast då ska roboten vara tillräckligt funktionell för att kunna klara av följande uppgift:
Starta c:a 50 cm från en vägg i en korridor (minst 150 cm bred, högst 400 cm; huvudsakligen släta väggar med förekomst av eluttag, glasade partier, golvlister och annat) i en slumpmässig riktning och därifrån leverera ett paket till en plats:
  1.	250 cm åt höger längs väggen, 0 - 30 cm från väggen.
  2.	250 cm åt vänster längs väggen, 0 - 30 cm från väggen.
  3.	250 cm åt höger, tvärs över korridoren, 0 - 30 cm från väggen på andra sidan korridoren.
  4.	250 cm åt vänster, tvärs över korridoren, 0 - 30 cm från väggen på andra sidan korridoren.

Innan varje uppdrag börjar får någon ur projektgruppen placera paketet på roboten. Paketet följer sedan med roboten till rätt destination enligt uppdraget. Vid destinationen ska roboten lasta av paketet och lämna det på golvet. Det paket som ska levereras är kurslitteraturen ”Arbeta i projekt - individen, gruppen, ledaren” av Sven Eklund.

Kraven ovan är ”Must enligt MoSCoW-modellen. ”Should”-krav är att roboten kan återvända till utgångsplatsen själv och vara klar för nästa leverans. ”Could”-kraven är att (1) roboten kan läsa in leveransadresser i form av streckkod, (2) att den kan leverera till verkliga kontorsrum eller lärosalar i Electrumhuset, och/eller (3) att det finns något ”enkelt” sätt att lära roboten nya leveransadresser.

Uppgiftägarens preferens är att roboten ska vara programmerad i språket C, men accepterar programmering i LEGO MINDSTORMS Education EV3 Classrom om föregående alternativ ej kan utföras innan deadline.

## Effektmål
Projektets effektmål är att levererad produkt ska ersätta beställarens befintliga resurser som är allokerade till detta; resultatet av denna ersättning ska vara en personalkostnadsreducering.

## Projektmål
Detta projekt har två projektmål: (1) att samtliga projektmedlemmar får tillräcklig kompetens och erfarenhet inom projektarbete och projektmetodik för att i framtiden kunna driva ett mindre IT-projekt i framtiden, samt att (2) detta resulterar i att projektmedlemmarna uppnår kursmålen och således blir godkända i kursen.

# Fas-, tids- och resursplan

## Tidsplan
Projektet startade 2021-09-08 och avslutas 2021-10-28. Tiden mellan dessa datum är uppdelade i sex iterationer och fyra faser (mer om faser följer i nästa sektion av kapitlet). Varje iteration är c:a en vecka lång och avslutas med ett handledningstillfälle, vars funktion är att granska projektets utveckling och agera milstolpe för iterationen. Vad som granskas under varje handledningstillfälle är specificerat under kapitel ”Rapport- och Granskningsplan”. Datum för handledningstillfällena är som följer:
  * Tillfälle 1: 2021-09-09
  * Tillfälle 2: 2021-09-17
  * Tillfälle 3: 2021-09-23
  * Tillfälle 4: 2021-09-30
  * Tillfälle 5: 2021-10-07

Utöver dessa finns ytterligare tre milstolpar; en projektpresentation i vilket varje enskild gruppmedlem presenterar projektet och dess innehåll; ett demonstrationstillfälle för att uppvisa att roboten levereras enligt kravspecifikationen; samt deadline för inlämning av kursrapporten, som inkluderar information och bilagor associerade till projektet. Datum för dessa är:
  * Projektpresentation: 2021-10-12
  * Projektdemonstration: 2021-10-13
  * Kursrapportinlämning: 2021-10-28

## Fasplan
Detta projekt inkluderar totalt fyra faser, som är uppdelade i ovan nämna fem iterationer:  ”Definitionsfas”, ”Planeringsfas” ”Utförandefas” och ”Utvärderingsfas”.

### Definitionsfas
Kan även refereras till som en ”Förstudie-fas”; gedigen utvärdering utav åtagna uppgiften genomförs och en grovplanering av projektets genomförande etableras. Resultatet av detta arbete finns speglas dels i detta dokument (projektdefinitionen), dels i kravspecifikationen. Båda agerar som milstolpar för Definitionsfasen.

### Planeringsfas
Varje iteration startar med en Planeringsfas; större problem bryts ned och delegeras på individnivå. Eventuella problemlösningsmöten utöver ordinarie möten bokas in.

### Utförandefas
Efter Planeringsfasen följer Utförandefasen, i vilket arbetet blir betydligt mer operativt orienterat; primärt sker arbete i form av C-programmering och justeringar av LEGO-robotens konstruktion.

### Utvärderingsfas
I Utvärderingsfasen granskas pågående iterations resultat och arbetsgången reflekteras över. Detta inkluderar funktionstester, dokumentgranskning och reflektionsmöte.

## Resursplan
I detta projektarbete har gruppen valt att arbeta med befintliga resurser såsom den av KTH givna LEGO MINDSTORMS-lådan, deltagarnas egna datorer, mjukvara som är gratis för allmänheten eller given av KTH till alla studenter samt KTH:s lokaler.
Den resurs som kan regleras av projektgruppen är projektmedlemmarnas arbetsinsats, uttryckt i antalet arbetstimmar. Projektgruppen har valt att budgetera 10 timmar / vecka / medlem, med flexibilitet att vissa veckor kan innebära mer arbetstid och andra mindre. 

# Intressenter
Detta projekt har följande intressenter
| Intressent                | Person / Organisation  | Påverkan                                                        |
|---------------------------|------------------------|-----------------------------------------------------------------|
| Projektledare             | Azmeer Akhtar Khawaja  | Påverkar direkt utfallet av projektarbetet                      |
| Projektmedlem             | Axel Lystam            | Påverkar direkt utfallet av projektarbetet                      |
| Projektmedlem             | Daniel Dahlberg        | Påverkar direkt utfallet av projektarbetet                      |
| Projektmedlem             | Marcus Cangren         | Påverkar direkt utfallet av projektarbetet                      |
| Uppgiftsägare             | Examinator             | Påverkar projektet direkt genom krav på slutprodukt             |
| Potentiella arbetsgivare  |                        | Påverkar projektet indirekt; förväntningar finns men är okända  |

# Riskanalys
Nedan följer en tabell med sammanställning av identifierade risker. Samtliga risker graderas på en skala 1-5 i termer av sannolikhet respektive påverkan, där 5 är högst sannolikt respektive högsta möjliga påverkan. Förebyggande åtgärd och åtgärd vid riskutfall planeras utefter riskens sannolikhet och påverkan.
| ID 	| Risk                                     	| Sannolikhet 	| Påverkan 	| Förebyggande åtgärd                                                                        	| Åtgärd vid riskutfall                                                             	|
|----	|------------------------------------------	|-------------	|----------	|--------------------------------------------------------------------------------------------	|-----------------------------------------------------------------------------------	|
| R1 	| Sjukdom i gruppen                        	| 2/5         	| 3/5      	| Överlappande ansvarsområden                                                                	| Delegering av ansvarsområde                                                       	|
| R2 	| C-kod ej funktionell innan deadline      	| 1/5         	| 4/5      	| Skapa backupkod i LEGO:s programmeringsmiljö                                               	| Övergå till backup                                                                	|
| R3 	| Okänt teknikfel under demonstration      	| 3/5         	| 5/5      	| Funktionstesta regelbundet och innan demosntration; notera vanliga fel och hur dessa löses 	| Kontrollera fysisk konstruktion; Reboot.                                          	|
| R4 	| Precision av givna LEGO-sensorer för låg 	| 3/5         	| 4/5      	| Gedigen utvärdering av precision och noggrannhet; korrigeringsfaktorer i kod               	| Implementera kontrollfunktioner / Inkludera kontrollmoment som korrigerar för fel 	|

# Förändringsplan
Projektet är öppet för förslag på ändringar från samtliga projektmedlemmar och från uppgiftsägaren. Nedan specificeras typer av ändringar som kan uppkomma under projektets gång, vem/vilka som har beslutsfattanderoll och en beskrivning av ändringsprocessen:
| Omfattning                   | Beskrivning                                                                                      | Beslutsfattare          | Process                                                                                                                        |
|------------------------------|--------------------------------------------------------------------------------------------------|-------------------------|--------------------------------------------------------------------------------------------------------------------------------|
| Hela projektet               | Ex. revidering av kravspecifikation, omfattande ändringar i arbetsfördelning eller tidsplanering | Projektgruppen          | Problemlösningsmöte kallas och adresserar ändringen. Beslut tas tillsammans av teamet. Ändringen noteras i relevanta dokument. |
| Överlappande ansvarsområden  | Ex. arbete med en del av koden som berör två teammedlemmars arbete                               | Berörda gruppmedlemmar  | Berörda personer tar tillsammans beslut och informerar teamet om ändringen. Ändringen noteras i relevanta dokument.            |
| En medlems ansvarsområde     | Ex. formulering av en funktion i robotens program                                                | Berörd individ          | Ansvarig person tar beslut och informerar gruppen om ändringen. Ändringen noteras i relevanta dokument.                        |

# Kostnadsplan
Nedan specificeras relevanta kostnadsposter, dessas budget samt finansiär:
| Kostnadspost          | Budget                     | Finansiär        |
|-----------------------|----------------------------|------------------|
| Arbetstimmar          | 280 timmar                 | Projektmedlemmar |
| LEGO MINDSTORMS       | Ej given av uppdragsgivare | KTH              |
| Lås för skåp          | 49 kr                      | Projektmedlemmar |
| Microsoft365          | Ej given av uppdragsgivare | KTH              |
| Uthyrning av lokaler  | Ej given av uppdragsgivare | KTH              |
| Utbildning            | Ej given av uppdragsgivare | KTH              |

# Dokumentplan
Nedan listas vilka dokument som skall användas, underhållas och/eller levereras.
| Dokument                  | Leveransdatum | Ansvarig        | Beskrivning                                                 |
|---------------------------|---------------|-----------------|-------------------------------------------------------------|
| Projektdefinition         | 2021-10-28    | Projektledare   | Grovplanering av projektet                                  |
| Kravspecifikation         | 2021-10-28    | Projektledare   | Sammanställning av krav på produkt                          |
| WBS-ritning               | 2021-10-28    | Projektledare   | Sammanställning av delproblem utav större problem           |
| Gantt-schema              | 2021-10-28    | Projektledare   | Flödesschema som beskriver faser i projektet                |
| Projekthistorik           | 2021-10-28    | Projektledare   |                                                             |
| Reflektionsmötesprotokoll |               | Projektgrupp    |                                                             |
| Socialt kontrakt          |               | Projektgrupp    | Kontrakt med regler för acceptabelt beteende inom gruppen   |
| Mötesprotokoll            |               | Protokollförare | Sammanställning av protokoll från gruppmöten                |

# Utbildningsplan
Behov av förstudie, inläsning, utbildning.
| Utbildningstyp         | Beskrivning                                         | Fas             | Budget                   |
|------------------------|-----------------------------------------------------|-----------------|--------------------------|
| Förstudie              |                                                     | Definitionsfas  | 40 timmar                |
|     - C-programmering  | Skapa basal förståelse för programmeringsspråket C  |                 |                          |
|     - ev3dev-c         | Skapa basal förståelse för ev3dev-c biblioteket     |                 |                          |
|     - SSH              | Skapa basal förståelse för användning av SSH        |                 |                          |
| Inläsning              |                                                     | Planeringsfas   | 40 timmar                |
|     - ev3dev-c syntax  | Få en solid uppfattning om ev3dev-c syntax          |                 |                          |
| Utbildning             |                                                     | Samtliga faser  | Ingår ej i projektbudget |
|     - Ingenjörsmetodik | Utbildning inom ämnen a relevans för projektarbete  |                 |                          |

# Rapport- och granskningsplan
Syfte och tider för rapportering och granskning följer:
| Granskningstillfälle  | Datum       | Granskare      | Punkter som granskas                                                                                                                                                             |
|-----------------------|-------------|----------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Handledning 1         | 2021-09-09  | Uppgiftsägare  | Socialt kontrakt, kontakt- och informationskanaler, arbetsplanering, tidsredovisning                                                                                             |
| Handledning 2         | 2021-09-17  | Uppgiftsägare  | Projektdefinition, tidrapport, WBS, iterationsplanering, resultat av reflektionsmöte, projektwebbsida, resultat av LEGO MINDSTORMS lådans inventering, basal mobilitet hos robot |
| Handledning 3         | 2021-09-23  | Uppgiftsägare  | Projektdefinition, tidrapport, Gantt-schema, resultat av reflektionsmöte, projektwebbsidan, iterationsplanering, nya funktioner/egenskaper hos robot                             |
| Handledning 4         | 2021-09-30  | Uppgiftsägare  | Tidrapport, resultat av reflektionsmöte, projektwebbsida, iterationsplanering, nya egenskaper/funktioner hos robot                                                               |
| Handledning 5         | 2021-10-07  | Uppgiftsägare  | Förslag på projektpresentation, tidsraport, resultat av reflektionsmöte, projektwebbsida, iterationsplanering, nya funktioner/egenskaper hos robot.                              |
| Projektpresentation   | 2021-10-12  | Uppgiftsägare  | Ej specificerat / Identifierat 2021-09-16                                                                                                                                        |
| Projektdemonstration  | 2021-10-13  | Uppgiftsägare  | Att LEGO-robot levereras enligt kravspecifikationen                                                                                                                              |
| Rapportutvärdering    | 2021-10-28  | Uppgiftsägare  | Dokument enligt specifikation under ”Dokumentplan”, kursrapport                                                                                                                  |
