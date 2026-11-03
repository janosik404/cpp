#include <string>

class zespolona {
    private:
        std::string nazwa;
        float rzecz;
        float urojo;

    public:
        zespolona();
        zespolona(std::string nazwa, float rzecz, float urojo);
        std::string toString();
        zespolona operator + (const zespolona &argP);
        friend zespolona operator + ( const float argL , const zespolona & argP);
        zespolona &operator++(); //++zespolona
        zespolona &operator++(int); //zespolona++


        friend std::ostream & operator << ( std::ostream &str, const zespolona & argP);

        bool operator == (const zespolona &argP);
};