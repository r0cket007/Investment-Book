#include<bits/stdc++.h>
using namespace std ;
fstream file ;
class Stock
{

    static double Total_Investment , Current_Investment, Total_Liquidity, profit_loss ;
    string Stock_Name ;
    int Quantity ;
    double Buy_Value , Total_Buy ;
    double Sell_Value , Total_Sell ;
    double percentage ;
  public :
    Stock( )
    {
      Stock_Name = " " ;
      Sell_Value = 0 ;
      Quantity = 0 ;
      Buy_Value = 0 ;
      Total_Buy = 0 ;
      Total_Sell = 0 ;
      percentage = 0.0 ;
    }
    Stock( string name , int qua , double value )
    {
      Stock_Name = name ;
      Quantity = qua ;
      Buy_Value = value ;
      Total_Buy = Quantity *  Buy_Value ;
      Total_Sell = 0 ;
      Sell_Value = 0 ;
      Total_Investment += Total_Buy ;
      Current_Investment += Total_Buy ;
    }
    bool Sell_Stock( int q , double price )
    {
        if( q > Quantity ) return false ;
        Quantity -= q ;
        Current_Investment -= ( q * Buy_Value ) ;
        Sell_Value = price ;
        Total_Sell += ( q * Sell_Value ) ;
        Total_Liquidity += Total_Sell ;
        profit_loss += ( ( q * Sell_Value ) - ( q * Buy_Value ) ) ;
        return true ;
    }
    bool Buy_Stock( int q , double price )
    {
        Quantity += q ;
        Current_Investment += ( q * price ) ;
        Total_Investment += ( q * price ) ;
        Buy_Value = ( Total_Buy + ( q * price ) ) / ( double)2 ;
        Total_Buy += ( q * price ) ;
        cout << "\nBOUGHT SUCCESSFULLY\n" ;
        return true ;
    }
    void Display( )
    {
        cout << Stock_Name << setw( 21 - Stock_Name.length( ) ) << Quantity << setw( 16 ) << Buy_Value << setw( 20 ) << Quantity * Buy_Value << setw( 13 ) << Total_Buy << setw( 15 ) << Total_Sell << '\t' ;
        cout << endl ;
    }
    void Display_Name( )
    {
      cout << Stock_Name << endl ;
    }
    static void Investment_Insight( )
    {
      cout << Total_Investment << setw( 25 ) << Total_Liquidity << setw( 28 ) << Current_Investment << setw( 20 ) << profit_loss << '\t' ;
      cout << endl ;
    }
    double getpercentage( )
    {
      return( ( ( Quantity * Buy_Value ) / Current_Investment )  * 100 ) ;
    }
    void Weightage( )
    {
      cout << Stock_Name << setw( 21 - Stock_Name.length( ) ) << getpercentage( ) ;
      cout << endl ;
    }
    int GetQuantity( )
    {
      return Quantity ;
    }
} ;
double Stock::Total_Investment = 0 ;
double Stock::Current_Investment = 0 ;
double Stock::Total_Liquidity = 0 ;
double Stock::profit_loss = 0 ;
int main( )
{
  file.open( "C:\\Users\\ASUS\\Documents\\coding\\input.txt") ;
  cout << "\t\t\t-----------------WELCOME TO INVESTEMENT BOOK-----------------------\n" ;
  vector<Stock> v ;
  int test_case = 1 ;
  int n = 0 ;
  while( test_case )
  {
    int choice ;
    cout << "\nENTER YOUR CHOICE :\n1.See Portfolio\n2.Show Weightage\n3.Investment insight\n4.Buy Stock\n5.Sell Stock\n6.Exit\n" ;
    cin >> choice ;
    sort( v.begin( ) , v.end( ) , [ ]( Stock a , Stock b ) { if( a.getpercentage( ) > b.getpercentage( ) ) return true ;}) ;
    switch( choice )
    {
        case 1 :
        {
            cout << "\nStock_Name" << '\t' << "Quantity" << '\t' << "Buy_Value" << '\t' << "Current_Total" << '\t' << "Total_Buy" << '\t' << "Total_Sell" << '\n' ;
            for( int i = 0 ; i < v.size( ) ; i ++ )
            {
                v[ i ].Display( ) ;
            }
            break ;
        }
        case 2 :
        {
            if( v.size( ) == 0 )
            {
                cout << "\nNO STOCK IN PORTFOLIO \n" ;
                break ;
            }
            for( int i = 0 ; i < v.size( ) ; i ++ )
            {
                v[ i ].Weightage( ) ;
            }
            cout << endl ;
            break ;
        }
        case 3 :
        {
            cout << "\nTotal_Investment" << '\t' << "Total_Liquidity" << "\t\t" << "Current_Investment" << '\t' << "profit_loss" << '\n' ;
            Stock::Investment_Insight( ) ;
            break ;
        }
        case 4 :
        {
            int m = 0 ;
            cout << "\nWANT TO BUY NEW STOCK PRESS 1 , FOR EXSISTING STOCK PRESS 2 \n" ;
            cin >> m ;
            int t, q ;
            double p ;
            if( m == 0 )
            {
                if( v.size( ) == 0 )
                {
                    cout << "\nNO STOCK IN PORTFOLIO \n" ;
                    break ;
                }
                cout << "\nWHICH STOCK YOU WANT TO BUY : \n" ;
                for( int i = 0 ; i < v.size( ) ; i ++ )
                {
                    cout << (i + 1) << " " ;
                    v[ i ].Display_Name( ) ;
                }
                cin >> t ;
                if( t > v.size( ) )
                {
                    cout << "\n----------------Wrong Input-------------------\n";
                    break ;
                }
                cout << "\nENTER QUNATITY :\n" ;
                cin >> q ;
                cout << "\nENTER PRICE :\n" ;
                cin >> p ;
                v[ t - 1 ].Buy_Stock( q , p ) ;
            }
            else
            {
                string s ;
                cout << "ENTER STOCK_NAME : \n" ;
                cin >> s ;
                cout << endl ;
                cout << "ENTER QUANTITY :\n" ;
                cin >> q ;
                cout << "\nENTER PRICE :\n" ;
                cin >> p ;
                Stock ob( s , q , p ) ;
                v.push_back( ob ) ;
            }
            break;
        }
        case 5 :
        {
            int t, q ;
            double p ;
            if( v.size( ) == 0 )
            {
                cout << "NO STOCK IN PORTFOLIO \n" ;
                break ;
            }
            cout << "WHICH STOCK YOU WANT TO BUY : \n" ;
            for( int i = 0 ; i < v.size( ) ; i ++ )
            {
                cout << (i + 1) << " " ;
                v[ i ].Display_Name( ) ;
            }
            cin >> t ;
            if( t > v.size( ) )
            {
                cout << "------------------Wrong Input----------------------\n";
                break ;
            }
            cout << "ENTER QUNATITY AND PRICE\n" ;
            cin >> q >> p ;
            if( v[ t - 1 ].Sell_Stock( q , p ) )
            {
              cout << "SOLD SUCCESSFULLY\n" ;
            }
            else cout << "------------------INVALID QUANTITY-----------------\n";
            if( v[ t - 1 ].GetQuantity( ) == 0 )
            {
              v.erase( v.begin( ) + ( t - 1 ) ) ;
            }
            break ;
        }
        case 6 :
        {
            test_case = 0 ;
            break ;
        }
        default :
        {
          cout << "----------------------Wrong choice------------------------\n";
        }
    }
  }
  return 0 ;
}
