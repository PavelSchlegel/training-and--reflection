#include <iostream>

class Sound
{
private:
    int m_sound_lenght;
public:
    Sound(int A)
    :m_sound_lenght(A)
    {

    }
    void get_suond()
    {
        for (int i = 0; i < m_sound_lenght; ++i) {
            std::cout << "Trrr-trrrr-trrr" << std::endl;
        }
    }
};

class Transformator
{
private:
    Sound m_sound;
public:
    Transformator()
    :m_sound(5)
    {
        m_sound.get_suond();
    }
};