// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include<iostream>
//using namespace std;
class Orario{
    private:
        int h;
        int m;
        int s;
        bool controlla_orario()
        {
            if(h < 0 || h>23 )
            {
                h = 0;
                m = 0;
                s = 0;
                return true;
            }
            if(m < 0 || m > 59)
            {
                h = 0;
                m = 0;
                s = 0; 
                return true;              
            }
            if(s < 0 || s > 59)
            {
                h = 0;
                m = 0;
                s = 0;  
                return true;             
            }
            return false;    
        }
        void to_orario(int secondi)
        {
            int tmp = secondi % 3600;
            h = secondi / 3600;
            m = tmp / 60;
            s =  tmp % 60; 
        }
    public:
        bool operator==(Orario a)const
        {
            if(a.h == h && a.m == m && a.s == s)    return true;
            return false;
        }
        bool operator<(Orario a)
        {
            int sec1 = a.to_second();
            int sec2 = to_second();
            if(sec1 > sec2)
                return true;
            return false;
        }
        Orario operator+(int secondi)
        {
            Orario r;
            int tmp = to_second();
            int t = tmp + secondi;
            to_orario(t);
            r.h = h;
            r.m = m;
            r.s = s;
            return r;
        }
        void stampa(std::ostream& os)
        {
            os<<h<<":"<<m<<":"<<s;
        }

        void leggi(std::istream& is)
        {
            char tmp;
            is>>h>>tmp>>m>>tmp>>s;
            if(controlla_orario())  std::cout<<"Orario errato"<<std::endl;
        }

        Orario()
        {
            h = 0;
            m = 0;
            s = 0;
            if(controlla_orario())  std::cout<<"Orario errato"<<std::endl;
        }
        Orario(int h, int m, int s)
        {
            this->h=h;
            this->m=m;
            this->s=s;   
            if(controlla_orario())  std::cout<<"Orario errato"<<std::endl;        
        }
        Orario(int s)
        {
            to_orario(s);
            if(controlla_orario())  std::cout<<"Orario errato"<<std::endl;
        }
        int get_ora()
        {
            return h;
        }
        int get_minuti()
        {
            return m;
        }
        int get_secondi()
        {
            return s;
        }
        int to_second()
        {
            int secondi = 0;
            secondi = s + m * 60 + h * 60 * 60;
        }

};


inline std::istream& operator>>(std::istream& i, Orario& a)
{
    a.leggi(i);
    return i;
}
inline std::ostream& operator<<(std::ostream& o, Orario a)
{
    a.stampa(o);
    return o;
}
