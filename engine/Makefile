# CXX := g++
# CXXFLAGS := -std=gnu++17 -O2 -Wall -Wextra -Wshadow -Wpedantic

# SRC := EnemyUnit.cpp Projectile.cpp TowerUnit.cpp World.cpp main.cpp
# HDR := Vec2.h Path.h EnemyUnit.h Projectile.h TowerUnit.h BuildSlots.h World.h Adapters.h


# USER_SRC := ../enemy.cpp ../goblin.cpp ../ogre.cpp ../ballista.cpp ../building.cpp ../farm.cpp ../player.cpp ../building_space.cpp ../skeleton.cpp ../mage_tower.cpp ../wave.cpp

# all: td_integrated

# td_integrated: $(SRC) $(HDR) $(USER_SRC)
# 	$(CXX) $(CXXFLAGS) $(SRC) $(USER_SRC) -I.. -o $@

# clean:
# 	rm -f td_integrated

#######
# # CXX := g++
# CXXFLAGS := -std=gnu++17 -O2 -Wall -Wextra -Wshadow -Wpedantic -I..

# # engine-side sources
# SRC := EnemyUnit.cpp Projectile.cpp TowerUnit.cpp World.cpp EngineAPI.cpp main.cpp

# # headers (not strictly required as deps, but OK to list)
# HDR := Vec2.h Path.h EnemyUnit.h Projectile.h TowerUnit.h BuildSlots.h World.h Adapters.h Spawner.h EngineAPI.h

# # your teammate’s / shared sources in parent directory
# USER_SRC := ../enemy.cpp ../goblin.cpp ../ogre.cpp ../ballista.cpp ../building.cpp \
#             ../farm.cpp ../player.cpp ../building_space.cpp ../skeleton.cpp \
#             ../mage_tower.cpp ../wave.cpp

# all: td_integrated

# td_integrated: $(SRC) $(USER_SRC)
# 	$(CXX) $(CXXFLAGS) $(SRC) $(USER_SRC) -o $@

# clean:
# 	rm -f td_integrated


CXX := g++
CXXFLAGS := -std=gnu++17 -O2 -Wall -Wextra -Wshadow -Wpedantic -I. -I..

# Core engine sources (NO main here)
CORE_SRC := EnemyUnit.cpp Projectile.cpp TowerUnit.cpp World.cpp EngineAPI.cpp
USER_SRC := ../enemy.cpp ../goblin.cpp ../ogre.cpp ../ballista.cpp ../building.cpp \
            ../farm.cpp ../player.cpp ../building_space.cpp ../skeleton.cpp \
            ../mage_tower.cpp ../wave.cpp

# Entry points
CONSOLE_MAIN := main.cpp
GUI_MAIN := gui_main.cpp

all: td_integrated

td_integrated: $(CORE_SRC) $(CONSOLE_MAIN) $(USER_SRC)
	$(CXX) $(CXXFLAGS) $(CORE_SRC) $(CONSOLE_MAIN) $(USER_SRC) -o $@

td_gui: $(CORE_SRC) $(GUI_MAIN) $(USER_SRC)
	$(CXX) $(CXXFLAGS) $(CORE_SRC) $(GUI_MAIN) $(USER_SRC) \
		-lsfml-graphics -lsfml-window -lsfml-system -o $@

clean:
	rm -f td_integrated td_gui
