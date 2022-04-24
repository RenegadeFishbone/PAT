#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printHeap(vector<int> &v){
    for(vector<int>::iterator it= v.begin();it!=v.end();++it){
        cout<< *it <<" ";
    }
    cout<<"\n"<<endl;
}

int main()
{
    vector<int> min={10,30,22,6,15,9};

    //����С����
    make_heap(min.begin(), min.end(), greater<int>());
    printHeap(min);//6 10 9 30 15 22

    //����Ԫ��
    min.push_back(20);
    push_heap(min.begin(),min.end(), greater<int>());//���㷨ǰ�᣺�����ڶѵ�������
    printHeap(min); //6 10 9 30 15 22 20   ��ΪС����

    //ɾ���Ѷ�Ԫ��
    pop_heap(min.begin(),min.end(), greater<int>());
    printHeap(min);//9 10 20 30 15 22 6  ��ΪС���� ���pop_heap������ʵ�����ǰѶѶ�Ԫ�طŵ���ĩβ
    min.pop_back();//��ų����ڵײ�vector����������ɾ��
    printHeap(min);//9 10 20 30 15 22  ��ΪС����

    //������  ����greater��С���ѣ��õ����ǽ���
    sort_heap(min.begin(),min.end(), greater<int>());//������less�������������
    printHeap(min);//30 22 20 15 10 9 ע�����ǽ����Ŷ!!!��ʵ�ǵ����˺ܶ��pop_heap(...,greater..)��ÿһ�ζ���С���ѶѶ���Ԫ����ĩβ�ţ�û��һ��end��������1

    return 0;
}

