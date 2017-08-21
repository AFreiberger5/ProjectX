#include "common.h"
#include "System.h"
#include "Scene1.h"
#include "Scene2.h"
#include "TestScene.h"
#include "Texture.h"

// Kommentar zur Projektaufteilung:
// Hinweis, das war die grobe Aufteilung, wenn man grade eine Idee hatte oder schnell mit einbem teil fertig wurde,
// wurde auch an anderen Teilen gearbeitet und über unser Gitrepo zusammengefügt, Anfängliche Aufteilung war wie folgt:
//
// Custovic war für Kollision, Player, Projektil zuständig
// Bloomenkamp für Background/UI/Scenen
// Freiberger für Enemies/Updates/Spielelogik
// 

int main(int argc, char *argv[])
{
	// System anlegen
	System s;

	// sdl starten und alle images laden
	if (s.init() && s.load())
	{
	
		Scene1 scene = Scene1(&s);

		s.changeScene(&scene);

		// programm ausfuehren
		s.run();
	}

	// speicher bereinigen
	s.clean();
}