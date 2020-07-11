#include<bits/stdc++.h>
using namespace std;

bool exists_test0 (const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}

int main(){
    // double cnt1=0,cnt2=0,cnt3=0,cnt4=0;
    // int agent = 1;
    //     while(agent < 4){
    //     int ex = 0;
    //     while(ex<100){
    //         double j = 1.250000000;
    //         while(j<6){
    //             int a = 5;
    //             while(a<21){
    //                 //cnt4 ++;
    //                 string string1 = "/home/mustafizur/pibt/log/8by8_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
    //                 string string2 = "/home/mustafizur/pibt/changed_log/8by8_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
    //                 string string3 = "/home/mustafizur/pibt/changed_changed_log/8by8_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
    //                 bool flag1 = false, flag2 = false,flag3=false;
    //                 if(exists_test0(string1)){
    //                     flag1 = true;
    //                     //cnt1 ++;
    //                     //cout<< string1 << endl;
    //                 }
    //                 if(exists_test0(string2)){
    //                     flag2 = true;
    //                     //cnt2 ++;
    //                 }
    //                 if(exists_test0(string3)){
    //                     flag3 = true;
    //                     //cnt3 ++;
    //                 }

    //                 if(flag1 && !flag3){
    //                     cnt1 ++;
    //                     cout<<string1<<endl;
    //                     //remove(string1.c_str());
    //                 }
    //                 else if(!flag1 && flag3){
    //                     cnt3 ++;
    //                     cout<<string3<<endl;
    //                     //remove(string3.c_str());
    //                 }

    //                 if(flag2 && !flag3){
    //                     cnt2 ++;
    //                     cout<<string2<<endl;
    //                     //remove(string2.c_str());
    //                 }
    //                 else if(!flag2 && flag3){
    //                     cnt4 ++;
    //                     cout<<string3<<endl;
    //                     //remove(string3.c_str());
    //                 }
    //                 a += 5;
    //             }
    //             j += 1;
    //         }
    //         ex +=1;
    //     }
    //     agent += 1;
    // }
    // cout<< cnt1 << " " << cnt2 << " " << cnt3 << " " << cnt4 <<endl;
    int a = 5;
    while(a<21){ 
        double j = 1.250000000;    
        int cnt = 0;
            double solncnt[4],runtimecnt[4],lowlevelcnt[4],solncost[4],solnruntime[4],solnlowlevel[4];
            for (size_t i = 0; i < 4; i++)
            {
                solncnt[i]=0,runtimecnt[i]=0,lowlevelcnt[i]=0,solncost[i]=0,solnruntime[i]=0,solnlowlevel[i]=0;
            } 
        while(j<6){
            int agent = 1; 
            while(agent<4){
                    int ex = 0;
                    while(ex<100){
                        string string1 = "/home/mustafizur/pibt/log/8by8_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        string string2 = "/home/mustafizur/pibt/changed_log/8by8_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        string string3 = "/home/mustafizur/pibt/changed_changed_log/8by8_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        bool flag1 = false, flag2 = false,flag3=false;
                        if(exists_test0(string1)){
                            flag1 = true;
                        }
                        if(exists_test0(string2)){
                            flag2 = true;
                        }
                        if(exists_test0(string3)){
                            flag3 = true;
                        }
                        if(flag1 && flag2 && flag3){
                            cnt++;
                            ifstream in1(string1);
                            ifstream in2(string2);
                            ifstream in3(string3);
                            string data;
                            while(getline(in1,data)){
                                stringstream check1(data);
                                string intermediate;
                                getline(check1,intermediate,':');
                                if(intermediate == "[solver] Lowlevelnode"){
                                    getline(check1,intermediate,':');
                                    lowlevelcnt[0] = atoi(intermediate.c_str());   
                                    cout << lowlevelcnt[0] <<endl;
                                }
                                else if(intermediate == "[solver] elapsed"){
                                    getline(check1,intermediate,':');
                                    runtimecnt[0] = atoi(intermediate.c_str());   
                                    cout << runtimecnt[0] <<endl;
                                }
                                else if(intermediate == "SolutionCost"){
                                    getline(check1,intermediate,':');
                                    solncnt[0] = atoi(intermediate.c_str());
                                    cout << solncnt[0] <<endl;
                                }
                            }
                        
                            while(getline(in2,data)){
                                stringstream check1(data);
                                string intermediate;
                                getline(check1,intermediate,':');
                                if(intermediate == "[solver] Lowlevelnode"){
                                    getline(check1,intermediate,':');
                                    lowlevelcnt[1] = atoi(intermediate.c_str());  
                                    cout << lowlevelcnt[1] <<endl; 
                                }
                                else if(intermediate == "[solver] elapsed"){
                                    getline(check1,intermediate,':');
                                    runtimecnt[1] = atoi(intermediate.c_str());   
                                    cout << runtimecnt[1] <<endl;
                                }
                                else if(intermediate == "SolutionCost"){
                                    getline(check1,intermediate,':');
                                    solncnt[1] = atoi(intermediate.c_str());
                                    cout << solncnt[1] <<endl;
                                }
                            }

                            while(getline(in3,data)){
                                stringstream check1(data);
                                string intermediate;
                                getline(check1,intermediate,':');
                                if(intermediate == "[solver] Lowlevelnode"){
                                    getline(check1,intermediate,':');
                                    lowlevelcnt[2] = atoi(intermediate.c_str()); 
                                    cout << lowlevelcnt[2] <<endl;  
                                }
                                else if(intermediate == "[solver] elapsed"){
                                    getline(check1,intermediate,':');
                                    runtimecnt[2] = atoi(intermediate.c_str());   
                                    cout<< runtimecnt[2] <<endl;
                                }
                                else if(intermediate == "SolutionCost"){
                                    getline(check1,intermediate,':');
                                    solncnt[2] = atoi(intermediate.c_str());
                                    cout << solncnt[2]<<endl;
                                }
                            }


                            // if(lowlevelcnt[0]>lowlevelcnt[2])
                            //     solnlowlevel[2] ++;
                            // else if(lowlevelcnt[0]<lowlevelcnt[2])
                            //     solnlowlevel[0] ++;
                            // else
                            //     solnlowlevel[0] ++,solnlowlevel[2] ++;

                            
                            // if(lowlevelcnt[1]>lowlevelcnt[2])
                            //     solnlowlevel[3] ++;
                            // else if(lowlevelcnt[1]<lowlevelcnt[2])
                            //     solnlowlevel[1] ++;
                            // else
                            //     solnlowlevel[1] ++,solnlowlevel[3] ++;

                            if(lowlevelcnt[2]==0){
                                solnlowlevel[0] += 1;
                                solnlowlevel[1] += 1;
                            }
                            else{
                                solnlowlevel[0] += lowlevelcnt[0]/lowlevelcnt[2];
                                solnlowlevel[1] += lowlevelcnt[1]/lowlevelcnt[2];
                            }

                            // if(runtimecnt[0]>runtimecnt[2])
                            //     solnruntime[2] ++;
                            // else if(runtimecnt[0]<runtimecnt[2])
                            //     solnruntime[0] ++;
                            // else
                            //     solnruntime[0] ++,solnruntime[2] ++;

                            // if(runtimecnt[1]>runtimecnt[2])
                            //     solnruntime[3] ++;
                            // else if(runtimecnt[1]<runtimecnt[2])
                            //     solnruntime[1] ++;
                            // else
                            //     solnruntime[1] ++,solnruntime[3] ++;

                            if(runtimecnt[2]==0){
                                solnruntime[0] += 1;
                                solnruntime[1] += 1;
                            }
                            else{
                                solnruntime[0] += runtimecnt[0]/runtimecnt[2];
                                solnruntime[1] += runtimecnt[1]/runtimecnt[2];
                            }

                            // if(solncnt[0]>solncnt[2])
                            //     solncost[2] ++;
                            // else if(solncnt[0]<solncnt[2])
                            //     solncost[0] ++;
                            // else
                            //     solncost[0] ++,solncost[2] ++;

                            // if(solncnt[1]>solncnt[2])
                            //     solncost[3] ++;
                            // else if(solncnt[1]<solncnt[2])
                            //     solncost[1] ++;
                            // else
                            //     solncost[1] ++,solncost[3] ++;


                            if(solncnt[2]==0){
                                solncost[0] += 1;
                                solncost[1] += 1;
                            }
                            else{
                                solncost[0] += solncnt[0]/solncnt[2]; 
                                solncost[1] += solncnt[1]/solncnt[2];
                            }
                            //cout<< lowlevelcnt1<< " " << lowlevelcnt2 << " " <<  runtimecnt1 << " " << runtimecnt2<<  " " << solncnt1 << " " << solncnt2<<endl;
                        }
                    ex += 1;

                    }
                agent += 1;
                }

            j += 1;
            }

        cout<< " agent = " << a << " instances = "  <<  cnt<<endl;    
            cout<<"LowLevel: "<<solnlowlevel[0]/cnt<< " "<< solnlowlevel[1]/cnt <<endl;
            cout<<"runitme: "<<solnruntime[0]/cnt<< " "<< solnruntime[1]/cnt <<endl;
            cout<<"Cost: "<<solncost[0]/cnt<< " "<< solncost[1]/cnt << endl;
        a += 5;
    }

    return 0;
}