#include<iostream>
#include<initializer_list>
#include<cmath>
using namespace std;

class Polinom  {
private:
    int stepen;
    double *koeficijenti;

public:
    Polinom();
    Polinom(int n);
    Polinom(int n, double* niz);
    Polinom(const Polinom& a);
    Polinom(initializer_list<double> lista);
    ~Polinom()  {delete[] koeficijenti;}
     Polinom& operator=(const Polinom& a);

    int vratiStepen()  const {return stepen;}
    double Evaluiraj(double x) ;
    double operator[](int indeks) const { return koeficijenti[indeks]; }
    double& operator[](int indeks)  { return koeficijenti[indeks]; }

    Polinom operator ~();
    friend Polinom operator+(const Polinom& a, const Polinom& b);
    friend bool operator==(const Polinom& a, const Polinom& b);
    friend ostream& operator<<(ostream& ispis, const Polinom& a);
};

Polinom::Polinom(): stepen(0) {
    koeficijenti = new double(0);

}

Polinom::Polinom(int n): stepen(n)  {
    koeficijenti = new double[n+1];
}

Polinom:: Polinom(const Polinom& a): stepen(a.stepen) {
   koeficijenti = new double[stepen +1];
   copy(a.koeficijenti, a.koeficijenti+ stepen + 1, koeficijenti);
   /*for(int i=0; i<= stepen; i++)
      koeficijenti[i]= a.koeficijenti[i];*/
}

Polinom::Polinom(initializer_list<double> lista): stepen(lista.size()-1) {
        koeficijenti = new double[stepen + 1];
        int i = 0;
        for(double el: lista) {
            koeficijenti[i] = el;
            i++;
        }
    }
    
    
Polinom::Polinom(int n, double* niz) : stepen(n) {
  koeficijenti = new double[stepen +1];
  copy(niz, niz + stepen + 1, koeficijenti);
  /*for(int i=0; i<=stepen; i++ )
      koeficijenti[i]= niz[i];*/
}

Polinom& Polinom::operator=(const Polinom& a)  {
   if(this == &a)  return *this;
   stepen = a.stepen;
   delete[] koeficijenti;
   koeficijenti = new double[stepen + 1];
   
   for(int i=0; i<= stepen; i++)
      koeficijenti[i] = a.koeficijenti[i];
   return* this;
}

 bool operator==(const Polinom& a, const Polinom& b) {
  if(a.stepen != b.stepen) return false;
  for(int i=0; i<=a.stepen;i++)
    if(a.koeficijenti[i] != b.koeficijenti[i]) return false;
  return true;
}

Polinom Polinom::operator ~() {
 Polinom izvod( (this->stepen) -1);
 for(int i=0; i<=izvod.stepen; i++) {
    izvod.koeficijenti[i] = (this->koeficijenti [i+1])*(i+1);
 }
 return izvod;
}


double Polinom::Evaluiraj(double x)   {
   double suma=0;
   for(int i=0; i<= stepen; i++)
      suma += koeficijenti[i] * (pow(x, i));
  return suma;
}

Polinom  operator +(const Polinom& a, const Polinom& b)  {
     Polinom zbir;
     if(a.stepen > b.stepen) {
        zbir = a;  
        for(int i=0; i<=b.stepen; i++)
            zbir.koeficijenti[i] +=  b.koeficijenti[i];
      }
    else  {            //tj. ako je a.stepen<=b.stepen
        zbir = b;     //zbir će imati isti stepen kao b
        for(int i=0; i<=a.stepen; i++)
            zbir.koeficijenti[i] +=  a.koeficijenti[i];
    }
    //sada treba odrediti stepen zbira
    //ako je npr. a= x^2 +5x +1, b= x^2+ 5x+1, zbir = 2x^2 +10x +2 je stepena 2
    //ali ako su a= x^2 +5x +1, b= -x^2+ 5x+1 polinomi stepena 2, njihov zbir = 10x + 2 je stepena 1 < 2
     int s = zbir.stepen; 
     
     while (zbir.koeficijenti[s] == 0) {
         s--;
         zbir.stepen= s;
         if (s<0)  {
             s=0; 
             break;
         }
         
     }
    zbir.stepen= s;
    
    return zbir;
}


ostream& operator<<(ostream& ispis, const Polinom& p) {
    if ( p.stepen ==0) {  
        ispis<<p[0];
        return ispis;
        }
    
   for(int i(p.stepen); i>0; i--)  {
      if(p.koeficijenti[i]!=0) {
         if(p.koeficijenti[i]!=1  and p.koeficijenti[i]!= -1 )
             ispis<<p.koeficijenti[i]<<"*";
         else if(p.koeficijenti[i] == -1 ) ispis<<"-";

         ispis<<"x^"<<i;
      }
      if(p.koeficijenti[i-1]> 0 )  ispis<<'+';

   }
    if(p.koeficijenti[0]!=0)  ispis<<p.koeficijenti[0];
    return ispis;
}

int main() {
    double niz[4]= {2, -1, 3, 6}; 
    double niz2[4]= {3, 1, -3, 5};  
    Polinom p1(3, &niz[0]);
    Polinom p2(3, &niz2[0]);
    Polinom p4(p1);
    Polinom p6{1,2,3,4,5,6};
    
    cout<<"p1 ="<<p1<<endl;
    cout<<"p2 ="<<p2<<endl;
    cout<<"p4 ="<<p4<<endl;
    cout<<"p6 ="<<p6<<endl;
    
    Polinom p5 = p1 +p2;
    cout<<"p5 ="<<p5<<endl;
    cout<<"stepen polinoma p5 je "<<p5.vratiStepen()<<endl;
  
    Polinom novi; // defaultni konstruktor
    cout<<"novi = "<<novi<<endl;
    
    Polinom q(3, &niz[0]);
    Polinom r(3, &niz2[0]);

    cout<<"q= "<<q<<endl;
 
   
    cout<<"Izvod polinoma q je "<<(~q)<<endl;
   
    cout<<"q(1)= "<<q.Evaluiraj(1)<<endl;


    cout<<"q[1] = "<<q[1]<<endl;
    q[1]= -3;
    cout<<"q[1] = "<<q[1]<<endl;

    r=q; // operator dodjele
    cout<<"r = "<<r<<endl;
    
    
    cout<<Polinom{0}<<endl;
    cout<<Polinom{1}<<endl;
    cout<<Polinom{-1}<<endl;
    cout<<Polinom{-1 , -2, 3, 4}<<endl;
 

}



