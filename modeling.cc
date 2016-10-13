#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>  
#include <time.h>       /* time */
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater
#include <iterator>
#include <math.h>

using namespace std;

int main(){

	std::priority_queue<bool> vip;
	vector<float> arrs;
	vector<float> servicing;
	vector<float> waiting;

	int n;
	float a, s, p;
	cin >> n;
	cin >> a;
	cin >> s;
	float avrWaitingTime =0;
	float randSer;
	float randarrival;
	float randarrivalHour;
	float finish = 0;
	float diff = 0;
	double v,rv;
	double iSecret, iGuess;
	long countpeople= 0;


  /* initialize random seed: */
  srand (time(NULL));

  int i =0;
  while(i<n){
	  randarrivalHour = 0;
	  while (randarrivalHour<7){
		v = (rand()%10);
		v = v/10;
		if(v>0.5){
			vip.push(1);
		}else{
			vip.push(0);
		}
		rv = (rand()%10);
		rv = rv/10;	
		randarrival = -log(1-v)*a;
		randarrivalHour = randarrivalHour + randarrival;
		
		randSer = -log(1-rv)*s;
		arrs.push_back(randarrivalHour);
		servicing.push_back(randSer);
		cout << "randarrivalHour is" << randarrivalHour << '\n';
		cout << "servise is" << randSer << '\n';
		system("pause");

	  }
	  std::vector<float>::iterator sr = servicing.begin();
	  for(std::vector<float>::iterator ar = arrs.begin(); ar != arrs.end(); ++ar){ 
		  if(finish > *ar){
			  float b = finish - *ar;
			  waiting.push_back(b);
			  finish = finish + *sr;
		  }else{
			finish = *ar + *sr;
		  }
		  ++sr;
	  }
	  countpeople = countpeople + arrs.size();
	  arrs.erase(arrs.begin(),arrs.end());
	  servicing.erase(servicing.begin(),servicing.end());
	  // Have to empty the que here.
	  // TODO
	i++;
  }
	for(std::vector<float>::iterator it = waiting.begin(); it != waiting.end(); ++it){
		diff = *it	+ diff;
	}
	cout << "Diff is";
	cout << diff;
	cout << "avg diff is";
	cout << diff/ (n * countpeople);

   system("pause");
}
