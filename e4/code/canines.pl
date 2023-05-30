canina(canis).
canina(cuon).
canina(lycaon).
canina(lupulella).

division(canis, canina).
division(cuon, canina).
division(lycaon, canina).
division(lupulella, canina).

canis(aureus).
canis(familiaris).
canis(latrans).
canis(lupaster).
canis(lupus).
canis(rufus).
canis(lycaon).
canis(simensis).

cuon(alpinus).

lycaon(pictus).

lupulella(adusta).
lupulella(mesomelas).

%-------------------

cerdocyonina(speothos).
cerdocyonina(lycalopex).
cerdocyonina(cerdocyon).
cerdocyonina(chrysocyon).
cerdocyonina(atelocynus).

speothos(venaticus).

lycalopex(culpaeus).
lycalopex(fulvipes).
lycalopex(griseus).
lycalopex(gymnocercus).
lycalopex(sechurae).
lycalopex(vetulus).

cerdocyon(thous).

chrysocyon(brachyrus).

atelocynus(microtis).

%-------------------

vulpini(nyctereutes).
vulpini(otocyon).
vulpini(vulpes).

nyctereutes(procyonoides).
nyctereutes(viverrinus).

otocyon(megalotis).

vulpes(bengalensis).
vulpes(cana).
vulpes(chama).
vulpes(corsac).
vulpes(ferrilata).
vulpes(lagopus).
vulpes(macrotis).
vulpes(pallida).
vulpes(rueppellii).
vulpes(velox).
vulpes(vulpes).
vulpes(zerda).

%-------------------

urocyon(urocyon).
urocyon(cinereoargenteus).
urocyon(littoralis).



partOf(Name, Genus, Division) :-
    Genus(Name),
    Division(Name).