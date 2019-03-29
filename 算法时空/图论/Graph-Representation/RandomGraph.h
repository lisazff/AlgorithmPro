//
//  Created by 佐毅 on 2018/3/18.
//  Copyright © 2018年 dfjr. All rights reserved.
//


#include <iostream>
#include <ctime>

using namespace std;

// 对图G随机生成边,边的个数的期望值为E
template <typename Graph>
class RandomGraph{

public:
    RandomGraph( Graph &graph, int V, int E){

        double p = (double)2*E / (V*(V-1));

        srand(time(NULL));
        for( int i = 0 ; i < V ; i ++ )
            for( int j = i+1 ; j < V ; j ++ ){

                double randomValue = (double)rand() / RAND_MAX;
                if( randomValue < p ){
                    graph.addEdge(i,j);
                }
            }
    }
};

