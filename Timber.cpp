#include <SFML/Graphics.hpp>
using namespace sf;
int main(){
    VideoMode vm(1920,1080);
    RenderWindow window(vm,"Timber Game");

    View view(FloatRect(0, 0,1920,1080));
    window.setView(view);

    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type==Event::Closed)
                window.close();
        }
    }
    window.clear();
    window.display();
    return 0;
}