# Kravspecifikation

## Bakgrund
Uppgiftsägaren har ett behov av att reducera personalkostnader för postutdelning i sina lokaler, och önskar därför få en LEGO robot levererad som kan ta över denna arbetsuppgift.

## Syfte
Projektets syfte är att producera en LEGO-robot som har förmågan att orientera sig, navigera till förprogrammerade punkter och avlasta post.

## Översikt

### Mål
Projektets resultatmål är att leverera LEGO-roboten i enlighet med kravspecifikationen på utsatt datum, 2021-10-13. Effektmålet är att denna robot kan bistå med att utdela post till olika adresser, och således minska på behovet för disponering av mänskliga resurser för detta. Projektgruppens interna mål är att samtliga projektmedlemmar får tillräckligt god förståelse för projektarbete så att de individuellt kan driva ett mindre IT-projekt i framtiden.

### Organisation

| Person                | Roll          | Kontaktinfo.   |
|-----------------------|---------------|----------------|
| Azmeer Akhtar Khawaja | Projektledare | aaak@kth.se    |
| Axel Lystam           | Projektmedlem | lystam@kth.se  |
| Daniel Dahlberg       | Projektmedlem | ddahlb@kth.se  |
| Marcus Cangren        | Projektmedlem | cangren@kth.se |
| KTH                   | Uppgiftsägare |                |

## Funktionella krav
LEGO roboten ska kunna klara av att starta c:a 50 cm från en vägg i en korridor (minst 150 cm bred, högst 400 cm; huvudsakligen släta väggar med förekomst av eluttag, glasade partier, golvlister och annat) i en slumpmässig riktning och därifrån leverera ett paket till en plats:
  1.	250 cm åt höger längs väggen, 0 - 30 cm från väggen.
  2.	250 cm åt vänster längs väggen, 0 - 30 cm från väggen.
  3.	250 cm åt höger, tvärs över korridoren, 0 - 30 cm från väggen på andra sidan korridoren.
  4.	250 cm åt vänster, tvärs över korridoren, 0 - 30 cm från väggen på andra sidan korridoren.

Precis innan varje uppdrag börjar får någon ur projektgruppen placera paketet på roboten. Paketet följer sedan med roboten till rätt destination enligt uppdraget. Vid destinationen ska roboten lasta av paketet och lämna det på golvet. Det paket som ska levereras är kurslitteraturen ”Arbeta i projekt - individen, gruppen, ledaren” av Sven Eklund.

## Icke-funktionella krav
Kraven ovan är ”Must enligt MoSCoW-modellen. 

”Should”-krav är att roboten kan återvända till utgångsplatsen själv och vara klar för nästa leverans.

”Could”-kraven är att:
  1. Roboten kan läsa in leveransadresser i form av streckkod
  2. Roboten kan leverera till verkliga kontorsrum eller lärosalar i Electrumhuset
  3. Roboten kan på ett ”enkelt” sätt lära sig nya leveransadresser.

Uppgiftägarens preferens är att roboten ska vara programmerad i språket C, men accepterar programmering i LEGO MINDSTORMS Education EV3 Classrom om föregående alternativ ej kan utföras innan deadline.

## Dokumentation
Ingen dokumentation har förfrågats. En välkommenterad programkod medföljer med LEGO-roboten.

## Leveransvillkor
Produkten levereras 2021-10-13 utan några garantier för framtida funktionallitet. Ingen betalning krävs av projektgruppen för åtagandet av projektet.
