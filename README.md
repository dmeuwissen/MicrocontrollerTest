# Wat is multithreading
Meerdere threads parallel laten uitvoeren op de CPU.
# Wanneer gebruik je meerdere threads?
Wanneer je een proces moet uitvoeren dat op de achtergrond moet gebeuren. Bijvoorbeeld data in de achtergrond ophalen zodat je GUI niet vastloopt. Of als je een langdurig proces hebt dat je sneller wil laten gaan door meer van de CPU tegelijk te kunnen gebruiken.
# Wat zijn drie veel voorkomende problemen bij mutithreaded applications? Waardoor ontstaan ze?

 - Hogeren complexiteit
 Aangezien je met multithreading veel extra code nodig hebt voor het aanmaken en bijhouden van de threads en het verdelen van het werk maakt dit de applicatie een stuk moeilijker te begrijpen dan met een single thread applicatie.
 - Moeilijker testen
Aangezien je nu ook de interactie tussen verschillende threads moet testen wordt dit een stuk moeilijker.
 - Onverwachte resultaten
De threads kunnen zorgen voor onverwachte resultaten wanneer resources bijvoorbeeld niet gelockt zijn. Hierdoor kunnen 2 threads tegelijk bij een object komen en deze tegelijk aanpassen waardoor er fouten ontstaan.

# Hoe wordt het onderdeel genoemd waar objecten in het geheugen worden geplaatst? 
De heap.
# Hoe is dit verschillend in een multithreaded application?
Niet. De heap is gedeeld in de verschillende threads.
# Hoe wordt het onderdeel genoemd waar methoden worden uitgevoerd en primitive types in het geheugen worden geplaatst?
De stack.
# Hoe is dit verschillend in een multithreaded application?
Iedere thread heeft een eigen stack.
# Wat is in dit kader een racing condition? Hoe zou je dit kunnen voorkomen?
Een racing condition is dat twee verschillende threads proberen hetzelfde object aan te passen. Dit kan opgelost worden doormiddel van een lock.