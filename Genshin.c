#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void Levelup(float *pm,float *pn,int n);

int main()
{
    srand((unsigned)time(NULL));
    int i,entry;
    //ͨ模拟圣遗物初始词条数，3词条4词条比例为4：1
    i = rand()%5;
    if(i == 0){
        entry = 4;
    }else{
        entry = 3;
    }
    float critR,critD,score;//暴击，爆伤
    critR = (float)(rand()%4 + 6.75)*0.4;
    critD = (float)(rand()%4 + 6.75)*0.8;

    for(i = 0;i <=entry;i++){
        Levelup(&critR,&critD,rand()%4+1);//Levelup函数来模拟升级过程
    }
    score = critR*2 + critD;

    printf("暴击率：%.1f%%   暴击伤害：%.1f%%\n",critR,critD);
    printf("双爆分：%.1f\n",score);
    if(score <= 20){
        printf("你怎么不强化啊\n");
    }
    if(score >20 && score <35){
        printf("勉强能用\n");
    }
    if(score >= 35 && score < 45){
        printf("半步帝器\n");
    }
    if(score >= 45){
        printf("你无敌了孩子\n");
    }

    return 0;
}

/*圣遗物强化过程有1/4的几率强化到双爆词条，暴击每次强化的数值是2.7 3.1 3.5 3.9，爆伤数值为双倍*/
void Levelup(float *pm,float *pn,int n)
{
    //n为1~4的随机数，对应升级的四种case
    switch (n)
    {
        case 1:
        *pm += (float)(rand()%4 + 6.75)*0.4;
        break;

        case 2:
        *pn += (float)(rand()%4 + 6.75)*0.8;

        case 3:
        break;

        case 4:
        break;
    }
}