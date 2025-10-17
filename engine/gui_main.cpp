#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>
#include <string>
#include "EngineAPI.h"

// simple waves here (UI owns wave progression)
static std::vector<std::vector<std::string>> waves = {
    {"goblin","goblin","goblin","goblin","goblin","goblin"},
    {"goblin","skeleton","goblin","skeleton","goblin","skeleton"},
    {"ogre","goblin","ogre","goblin","skeleton","ogre","goblin"},
};

static sf::Vector2f screenFromWorld(const Vec2& v, float scale=40.f, sf::Vector2f origin={60.f, 420.f}){
    // world y+ is up; screen y+ is down → flip Y
    return { origin.x + v.x * scale, origin.y - v.y * scale };
}

int main(){
    // 1) init window
    sf::RenderWindow window(sf::VideoMode(900, 520), "TD GUI");
    window.setFramerateLimit(60);

    // 2) init engine
    Engine engine;
    engine.loadDefaultMap();     // seeds path+slots
    engine.setDifficulty(2);
    engine.setTimeScale(0.8f);

    size_t waveIndex = 0;
    engine.startWave(waves[waveIndex], 0.6f);

    int selectedTowerType = 1;   // 1=Ballista, 2=Mage, 3=Farm

    // 3) main loop
    while (window.isOpen()){
        // -- input
        sf::Event ev;
        while (window.pollEvent(ev)){
            if (ev.type == sf::Event::Closed) window.close();

            if (ev.type == sf::Event::KeyPressed){
                if (ev.key.code == sf::Keyboard::Num1) selectedTowerType = 1;
                if (ev.key.code == sf::Keyboard::Num2) selectedTowerType = 2;
                if (ev.key.code == sf::Keyboard::Num3) selectedTowerType = 3;
                if (ev.key.code == sf::Keyboard::Add)  engine.setTimeScale(engine.getTimeScale()+0.1f);
                if (ev.key.code == sf::Keyboard::Subtract) engine.setTimeScale(engine.getTimeScale()-0.1f);
                if (ev.key.code == sf::Keyboard::N){ // start next wave
                    if (!engine.isWaveActive()){
                        if (waveIndex + 1 < waves.size()){
                            ++waveIndex;
                            engine.startWave(waves[waveIndex], 0.6f);
                        }
                    }
                }
            }

            // mouse left: build on nearest slot if close
            if (ev.type == sf::Event::MouseButtonPressed && ev.mouseButton.button==sf::Mouse::Left){
                auto state = engine.getState();
                float bestD2 = 1e9f; int bestIdx = -1;
                for (int i=0; i<engine.slotCount(); ++i){
                    auto sp = screenFromWorld(engine.slotPos(i));
                    float dx = sp.x - ev.mouseButton.x;
                    float dy = sp.y - ev.mouseButton.y;
                    float d2 = dx*dx + dy*dy;
                    if (d2 < bestD2){ bestD2 = d2; bestIdx = i; }
                }
                if (bestIdx >= 0 && bestD2 <= 20.f*20.f){ // click near a slot
                    engine.build(bestIdx, selectedTowerType);
                }
            }

            // mouse right: sell if near a slot
            if (ev.type == sf::Event::MouseButtonPressed && ev.mouseButton.button==sf::Mouse::Right){
                float bestD2 = 1e9f; int bestIdx = -1;
                for (int i=0; i<engine.slotCount(); ++i){
                    auto sp = screenFromWorld(engine.slotPos(i));
                    float dx = sp.x - ev.mouseButton.x;
                    float dy = sp.y - ev.mouseButton.y;
                    float d2 = dx*dx + dy*dy;
                    if (d2 < bestD2){ bestD2 = d2; bestIdx = i; }
                }
                if (bestIdx >= 0 && bestD2 <= 20.f*20.f){
                    engine.sell(bestIdx);
                }
            }
        }

        // -- update engine (fixed 60 FPS)
        engine.tick(1.0f/60.0f);
        auto state = engine.getState();

        // auto-start next wave when current finished (optional)
        if (state.waveDone && waveIndex + 1 < waves.size()){
            // wait for user pressing N in a real UI; here we could auto-start:
            // ++waveIndex; engine.startWave(waves[waveIndex], 0.6f);
        }

        // -- draw
        window.clear(sf::Color(25,28,35));

        // path (just draw the polyline)
        sf::VertexArray pathLines(sf::LineStrip);
        for (auto& wp : {Vec2{0,0}, Vec2{8,0}, Vec2{8,4}, Vec2{14,4}, Vec2{14, 8}, Vec2{14,12}}){
            pathLines.append(sf::Vertex(screenFromWorld(wp), sf::Color(120,120,120)));
        }
        window.draw(pathLines);

        // build slots
        for (int i=0; i<engine.slotCount(); ++i){
            sf::CircleShape slot(8.f);
            slot.setOrigin(8.f,8.f);
            slot.setPosition(screenFromWorld(engine.slotPos(i)));
            slot.setFillColor(sf::Color(70,70,90));
            slot.setOutlineColor(sf::Color(160,160,220));
            slot.setOutlineThickness(2.f);
            window.draw(slot);
        }

        // towers
        for (auto& t : state.towers){
            sf::RectangleShape body({14.f,14.f});
            body.setOrigin(7.f,7.f);
            body.setPosition(screenFromWorld({t.x, t.y}));
            body.setFillColor(sf::Color(180,180,220));

            // range circle (subtle)
            sf::CircleShape rng(t.range*40.f);
            rng.setOrigin(t.range*40.f, t.range*40.f);
            rng.setPosition(screenFromWorld({t.x, t.y}));
            rng.setFillColor(sf::Color(0,0,0,0));
            rng.setOutlineThickness(1.f);
            rng.setOutlineColor(sf::Color(80,100,160,120));

            window.draw(rng);
            window.draw(body);
        }

        // enemies
        for (auto& e : state.enemies){
            sf::CircleShape blob(7.f);
            blob.setOrigin(7.f,7.f);
            blob.setPosition(screenFromWorld({e.x, e.y}));
            blob.setFillColor(sf::Color(220,110,110));
            window.draw(blob);

            // tiny HP bar
            float pct = e.max_hp ? (float)e.hp / (float)e.max_hp : 0.f;
            sf::RectangleShape hpbg({16.f, 3.f});
            hpbg.setOrigin(8.f, 10.f);
            hpbg.setPosition(screenFromWorld({e.x, e.y}));
            hpbg.setFillColor(sf::Color(50,50,50));
            window.draw(hpbg);

            sf::RectangleShape hp({16.f*pct, 3.f});
            hp.setOrigin(8.f, 10.f);
            hp.setPosition(screenFromWorld({e.x, e.y}));
            hp.setFillColor(sf::Color(80,230,80));
            window.draw(hp);
        }

        // projectiles
        for (auto& p : state.projectiles){
            sf::CircleShape shot(3.f);
            shot.setOrigin(3.f,3.f);
            shot.setPosition(screenFromWorld({p.x, p.y}));
            shot.setFillColor(sf::Color(240,240,150));
            window.draw(shot);
        }

        // HUD text (use a default font if you have one—omitted here for brevity)
        // You can replace with ImGui later.

        window.display();
    }
    return 0;
}
