// 这是我在citadel的面试题目，其实题目挺简单的，但是c++的代码明显练习不够
// 基本思路是维护递增和递减的map，分别从小到大进行匹配，如果匹配成功(buy > sell)，
// 实现利润，就可以完成交易


#include<iostream>
#include<map>
using namespace std;

class TradingSystem {
private:
  map<float, int> sellMap; // increasing order
  map<float, int, greater<>> buyMap; // decreasing order
  float totalProfit = 0.0;

public:
  int buy(int num_of_product, float price) {
    int totalBuy = 0;
    for (auto it = sellMap.begin(); it != sellMap.end();) {
      float t_price = it->first;
      int t_count = it->second;
      if (price >= t_price) {
        int remain = num_of_product - t_count;
        if (remain < 0) {
          totalProfit += (price-t_price) * num_of_product;
          totalBuy += num_of_product;
          num_of_product = 0;
          sellMap[t_price] = -remain;
          break;
        } else {
          totalProfit += (price-t_price) * t_count;
          totalBuy += t_count;
          num_of_product = remain;
          it = sellMap.erase(it);
        }
      } else {
        break;
      }
    }

    if (num_of_product > 0) {
      buyMap[price] = num_of_product;
    }

    return totalBuy;
  }


  int sell(int num_of_product, float price) {
    int totalSell = 0;
    for (auto it = buyMap.begin(); it != buyMap.end();) {
      float t_price = it->first;
      int t_count = it->second;
      if (price <= t_price) {
        int remain = num_of_product - t_count;
        if (remain < 0) {
          totalProfit += (t_price-price) * num_of_product;
          totalSell += num_of_product;
          num_of_product = 0;
          buyMap[t_price] = -remain;
          break;
        } else {
          totalProfit += (t_price-price) * t_count;
          totalSell += t_count;
          num_of_product = remain;
          it = buyMap.erase(it);
        }
      } else {
        break;
      }
    }

    if (num_of_product > 0) {
      sellMap[price] = num_of_product;
    }

    return totalSell;
  }

  float get_profits() {
    return totalProfit;
  }
};

// To execute C++, please define "int main()"
int main() {

  TradingSystem system;
  cout << system.sell(50, 1.5) << endl;
  cout << system.sell(20, 1.4) << endl;
  cout << system.buy(60, 1.51) << endl;
  cout << system.get_profits() << endl;
  cout << system.buy(20, 1.5) << endl;
  cout << system.get_profits() << endl;
  cout << system.sell(20, 0.7) << endl;
  cout << system.buy(100, 0.6) << endl;
  cout << system.get_profits()  << endl;

  return 0;
}


/*

Implement a trading system receiving incoming stream of trade orders. 

buy(num_of_product, price)
Called by buyer to buy certain number of products with a maximum price
num_of_product (INTEGER): number of products to buy
price (FLOAT): maximal price/unit the buyer is willing to pay
Return (INTEGER): number of products can be bought


sell(num_of_product, price)
Called by seller to sell certain number of products with a minimum price
num_of_product (INTEGER): number of products to sell
price (FLOAT): minimal price/unit the seller is willing to sell
Return (INTEGER): number of products can be sold


we take price difference between sell and buy orders as profits. We wanted to maximize the profits. 
get_profits()
Return (FLOAT): accumulated profits 


system = TradingSystem()
system.sell(50, 1.5)
return: 0

system.sell(20, 1.4)
return: 0

system.buy(60, 1.51) 
return: 60

system.get_profits() 
return: 2.6 60*1.51 - 20*1.4-40*1.5 = 2.6 

system.buy(20, 1.5)
return: 10              (10,1.5) (sell)

system.get_profits() 
return: 2.6.            

system.sell(20, 0.7)
return: 10         20*0.7=14.  (10 0.7)  

system.buy(100, 0.6)
return: 0.        0

system.get_profits() 
return: 10.6       2.6+(1.5-0.7)*10 = `10.6 
*/