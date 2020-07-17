#include<bits/stdc++.h>
using namespace std;

bool exists_test0 (const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}

int main(){
    int ans;
    //bool success = false, completeness = false, percentage = false, performance = false;
    cout << "For success input 1" << endl ;
    cout << "For completeness input 2" << endl ;
    cout << "For percentage_weight input 3" << endl;
    cout << "For percentage_agent input 4" << endl;
    cout << "For percentage_weight_agent input 5" << endl;
    cout << "For performance_weight input 6" <<endl;
    cout << "For performance_agent input 7" <<endl;
    cout << "For performance_weight_agent input 8" <<endl;
    cin >> ans;
    double cnt1=0,cnt2=0,cnt3=0,cnt4=0,cnt5=0,cnt6=0;
    double j = 1.250000000;
    int agent = 10, a = 10;
    switch (ans)
    {
    case 1:
        // for succsess and completeness
        while(j<6){
            a = 10;
            while(a<101){
                int ex = 0;
                while(ex<10){
                cnt4 ++;
                // string string1 = "/home/mustafizur/pibt/log/32by32_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                // string string2 = "/home/mustafizur/pibt/changed_log/32by32_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                // string string3 = "/home/mustafizur/pibt/changed_changed_log/32by32_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                
                string string1 = "/home/mustafizur/pibt/log/warehouse_middle_" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                string string2 = "/home/mustafizur/pibt/changed_log/warehouse_middle_" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                string string3 = "/home/mustafizur/pibt/changed_changed_log/warehouse_middle_" + to_string(ex) + "_" +  to_string(a)+ "_" + to_string(j) + ".txt";


                bool flag1 = false, flag2 = false,flag3=false;
                if(exists_test0(string1)){
                    flag1 = true;
                    cnt1 ++;
                    //cout<< string1 << endl;
                }
                if(exists_test0(string2)){
                    flag2 = true;
                    cnt2 ++;
                }
                if(exists_test0(string3)){
                    flag3 = true;
                    cnt3 ++;
                }
                ex += 1;
                }
                a += 10;
            }
            j += 1;
        }
        cout<< cnt1/cnt4 << " " << cnt2/cnt4 << " " << cnt3/cnt4 << " " << cnt4 <<endl;

        break;
    
    case 2:
        // for succsess and completeness
        while(j<6){
            a = 10;
            while(a<101){
                int ex = 0;
                while(ex<10){

                // string string1 = "/home/mustafizur/pibt/log/32by32_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                // string string2 = "/home/mustafizur/pibt/changed_log/32by32_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                // string string3 = "/home/mustafizur/pibt/changed_changed_log/32by32_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                
                string string1 = "/home/mustafizur/pibt/log/warehouse_middle_" + to_string(ex) + "_" +  to_string(a)+ "_" + to_string(j) + ".txt";
                string string2 = "/home/mustafizur/pibt/changed_log/warehouse_middle_" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                string string3 = "/home/mustafizur/pibt/changed_changed_log/warehouse_middle_" + to_string(ex) + "_" +  to_string(a)+ "_" + to_string(j) + ".txt";


                bool flag1 = false, flag2 = false,flag3=false;
                if(exists_test0(string1)){
                    flag1 = true;
                    //cout<< string1 << endl;
                }
                if(exists_test0(string2)){
                    flag2 = true;
                }
                if(exists_test0(string3)){
                    flag3 = true;
                }

                if(flag1 && !flag3){
                    cnt1 ++;
                    cout<<string1<<endl;
                    //remove(string1.c_str());
                }
                else if(!flag1 && flag3){
                    cnt3 ++;
                    cout<<string3<<endl;
                    //remove(string3.c_str());
                }

                if(flag1 && !flag2){
                    cnt5 ++;
                    cout<<string1<<endl;
                    //remove(string1.c_str());
                }
                else if(!flag1 && flag2){
                    cnt6 ++;
                    cout<<string2<<endl;
                    //remove(string3.c_str());
                }

                if(flag2 && !flag3){
                    cnt2 ++;
                    cout<<string2<<endl;
                    //remove(string2.c_str());
                }
                else if(!flag2 && flag3){
                    cnt4 ++;
                    cout<<string3<<endl;
                    //remove(string3.c_str());
                }
                ex += 1;
                }
                a += 10;
            }
            j += 1;
        } 

        cout << cnt1 << " problems which were solved by ECBS were not solved by ECBS-changed_2." <<endl; 
        cout << cnt3 << " problems which were solved by ECBS-changed_2 were not solved by ECBS." << endl;
        cout << cnt2 << " problems which were solved by ECBS-changed were not solved by ECBS-changed_2." << endl;
        cout << cnt4 << " problems which were solved by ECBS-changed_2 were not solved by ECBS-changed." << endl;      
        cout << cnt5 << " problems which were solved by ECBS were not solved by ECBS-changed." <<endl; 
        cout << cnt6 << " problems which were solved by ECBS-changed were not solved by ECBS." << endl; 


        break;

    case 3:
        j = 1.250000000;
        while(j<6){ 
            a = 10;
            int cnt = 0;
                double solncnt[6],runtimecnt[6],lowlevelcnt[6],solncost[6],solnruntime[6],solnlowlevel[6];
                for (size_t i = 0; i < 6; i++)
                {
                    solncnt[i]=0,runtimecnt[i]=0,lowlevelcnt[i]=0,solncost[i]=0,solnruntime[i]=0,solnlowlevel[i]=0;
                } 
            while(a<101){
                // int agent = 10;  
                // //while(agent<4){
                int ex = 0;
                while(ex<10){
                        // string string1 = "/home/mustafizur/pibt/log/8by8_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        // string string2 = "/home/mustafizur/pibt/changed_log/8by8_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        // string string3 = "/home/mustafizur/pibt/changed_changed_log/8by8_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        
                        // string string1 = "/home/mustafizur/pibt/log/32by32_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        // string string2 = "/home/mustafizur/pibt/changed_log/32by32_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        // string string3 = "/home/mustafizur/pibt/changed_changed_log/32by32_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
    


                        string string1 = "/home/mustafizur/pibt/log/warehouse_middle_" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        string string2 = "/home/mustafizur/pibt/changed_log/warehouse_middle_" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        string string3 = "/home/mustafizur/pibt/changed_changed_log/warehouse_middle_" + to_string(ex) + "_" +  to_string(a)+ "_" + to_string(j) + ".txt";

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
                                    //cout << lowlevelcnt[0] <<endl;
                                }
                                else if(intermediate == "[solver] elapsed"){
                                    getline(check1,intermediate,':');
                                    runtimecnt[0] = atoi(intermediate.c_str());   
                                    //cout << runtimecnt[0] <<endl;
                                }
                                else if(intermediate == "SolutionCost"){
                                    getline(check1,intermediate,':');
                                    solncnt[0] = atoi(intermediate.c_str());
                                    //cout << solncnt[0] <<endl;
                                }
                            }
                        
                            while(getline(in2,data)){
                                stringstream check1(data);
                                string intermediate;
                                getline(check1,intermediate,':');
                                if(intermediate == "[solver] Lowlevelnode"){
                                    getline(check1,intermediate,':');
                                    lowlevelcnt[1] = atoi(intermediate.c_str());  
                                    //cout << lowlevelcnt[1] <<endl; 
                                }
                                else if(intermediate == "[solver] elapsed"){
                                    getline(check1,intermediate,':');
                                    runtimecnt[1] = atoi(intermediate.c_str());   
                                    //cout << runtimecnt[1] <<endl;
                                }
                                else if(intermediate == "SolutionCost"){
                                    getline(check1,intermediate,':');
                                    solncnt[1] = atoi(intermediate.c_str());
                                    //cout << solncnt[1] <<endl;
                                }
                            }

                            while(getline(in3,data)){
                                stringstream check1(data);
                                string intermediate;
                                getline(check1,intermediate,':');
                                if(intermediate == "[solver] Lowlevelnode"){
                                    getline(check1,intermediate,':');
                                    lowlevelcnt[2] = atoi(intermediate.c_str()); 
                                    //cout << lowlevelcnt[2] <<endl;  
                                }
                                else if(intermediate == "[solver] elapsed"){
                                    getline(check1,intermediate,':');
                                    runtimecnt[2] = atoi(intermediate.c_str());   
                                    //cout<< runtimecnt[2] <<endl;
                                }
                                else if(intermediate == "SolutionCost"){
                                    getline(check1,intermediate,':');
                                    solncnt[2] = atoi(intermediate.c_str());
                                    //cout << solncnt[2]<<endl;
                                }
                            }


                            if(lowlevelcnt[0]>lowlevelcnt[2])
                                solnlowlevel[4] ++; // ecbs_2 better than ecbs
                            else if(lowlevelcnt[0]<lowlevelcnt[2])
                                solnlowlevel[0] ++; // ecbs better than ecbs_2

                            
                            if(lowlevelcnt[1]>lowlevelcnt[2])
                                solnlowlevel[5] ++; // ecbs_2 better than ecbs_1
                            else if(lowlevelcnt[1]<lowlevelcnt[2])
                                solnlowlevel[3] ++; // ecbs_1 better than ecbs_2

                            if(lowlevelcnt[0]>lowlevelcnt[1])
                                solnlowlevel[2] ++; // ecbs_1 better than ecbs
                            else if(lowlevelcnt[0]<lowlevelcnt[1])
                                solnlowlevel[1] ++; // ecbs better than ecbs_1

                    
                            if(runtimecnt[0]>runtimecnt[2])
                                solnruntime[4] ++; // ecbs_2 better than ecbs
                            else if(runtimecnt[0]<runtimecnt[2])
                                solnruntime[0] ++; // ecbs better than ecbs_2

                            
                            if(runtimecnt[1]>runtimecnt[2])
                                solnruntime[5] ++; // ecbs_2 better than ecbs_1
                            else if(runtimecnt[1]<runtimecnt[2])
                                solnruntime[3] ++; // ecbs_1 better than ecbs_2

                            if(runtimecnt[0]>runtimecnt[1])
                                solnruntime[2] ++; // ecbs_1 better than ecbs
                            else if(runtimecnt[0]<runtimecnt[1])
                                solnruntime[1] ++; // ecbs better than ecbs_1

                        
                            if(solncnt[0]>solncnt[2])
                                solncost[4] ++; // ecbs_2 better than ecbs
                            else if(solncnt[0]<solncnt[2])
                                solncost[0] ++; // ecbs better than ecbs_2

                            
                            if(solncnt[1]>solncnt[2])
                                solncost[5] ++; // ecbs_2 better than ecbs_1
                            else if(solncnt[1]<solncnt[2])
                                solncost[3] ++; // ecbs_1 better than ecbs_2

                            if(solncnt[0]>solncnt[1])
                                solncost[2] ++; // ecbs_1 better than ecbs
                            else if(solncnt[0]<solncnt[1])
                                solncost[1] ++; // ecbs better than ecbs_1

                        }
                        ex += 1;

                        }
                    // agent += 1;
                    // }

                a += 10;
                }

            cout<< "weight = " << j <<" instances = "  <<  cnt<<endl;  
            cout << "ecbs > ecbs2   ecbs > ecbs1    ecbs1 > ecbs   ecbs1 > ecbs2    ecbs2 > ecbs    ecbs2 > ecbs1" << endl;   
            cout<<"LowLevel: "<<endl;
            for (size_t i = 0; i < 6; i++)
            {
                cout << (solnlowlevel[i]/cnt)*100<< " ";
            }
            cout<<endl<<"runitme: "<<endl;
            for (size_t i = 0; i < 6; i++)
            {
                cout << (solnruntime[i]/cnt)*100<< " ";
            }
            cout<<endl<<"Cost: "<<endl;
            for (size_t i = 0; i < 6; i++)
            {
                cout << (solncost[i]/cnt)*100<< " ";
            }
            cout << endl;
            j += 1;
        }


        break;

    case 4:
        a = 10;
        while(a<101){
            double j = 1.250000000;
            int cnt = 0;
                double solncnt[6],runtimecnt[6],lowlevelcnt[6],solncost[6],solnruntime[6],solnlowlevel[6];
                for (size_t i = 0; i < 6; i++)
                {
                    solncnt[i]=0,runtimecnt[i]=0,lowlevelcnt[i]=0,solncost[i]=0,solnruntime[i]=0,solnlowlevel[i]=0;
                } 
            while(j<6){
                // int agent = 10;  
                // //while(agent<4){
                    int ex = 0;
                    while(ex<10){
                        // string string1 = "/home/mustafizur/pibt/log/8by8_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        // string string2 = "/home/mustafizur/pibt/changed_log/8by8_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        // string string3 = "/home/mustafizur/pibt/changed_changed_log/8by8_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        
                        // string string1 = "/home/mustafizur/pibt/log/32by32_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        // string string2 = "/home/mustafizur/pibt/changed_log/32by32_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        // string string3 = "/home/mustafizur/pibt/changed_changed_log/32by32_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
    


                        string string1 = "/home/mustafizur/pibt/log/warehouse_middle_" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        string string2 = "/home/mustafizur/pibt/changed_log/warehouse_middle_" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        string string3 = "/home/mustafizur/pibt/changed_changed_log/warehouse_middle_" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";

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
                                    //cout << lowlevelcnt[0] <<endl;
                                }
                                else if(intermediate == "[solver] elapsed"){
                                    getline(check1,intermediate,':');
                                    runtimecnt[0] = atoi(intermediate.c_str());   
                                    //cout << runtimecnt[0] <<endl;
                                }
                                else if(intermediate == "SolutionCost"){
                                    getline(check1,intermediate,':');
                                    solncnt[0] = atoi(intermediate.c_str());
                                    //cout << solncnt[0] <<endl;
                                }
                            }
                        
                            while(getline(in2,data)){
                                stringstream check1(data);
                                string intermediate;
                                getline(check1,intermediate,':');
                                if(intermediate == "[solver] Lowlevelnode"){
                                    getline(check1,intermediate,':');
                                    lowlevelcnt[1] = atoi(intermediate.c_str());  
                                    //cout << lowlevelcnt[1] <<endl; 
                                }
                                else if(intermediate == "[solver] elapsed"){
                                    getline(check1,intermediate,':');
                                    runtimecnt[1] = atoi(intermediate.c_str());   
                                    //cout << runtimecnt[1] <<endl;
                                }
                                else if(intermediate == "SolutionCost"){
                                    getline(check1,intermediate,':');
                                    solncnt[1] = atoi(intermediate.c_str());
                                    //cout << solncnt[1] <<endl;
                                }
                            }

                            while(getline(in3,data)){
                                stringstream check1(data);
                                string intermediate;
                                getline(check1,intermediate,':');
                                if(intermediate == "[solver] Lowlevelnode"){
                                    getline(check1,intermediate,':');
                                    lowlevelcnt[2] = atoi(intermediate.c_str()); 
                                    //cout << lowlevelcnt[2] <<endl;  
                                }
                                else if(intermediate == "[solver] elapsed"){
                                    getline(check1,intermediate,':');
                                    runtimecnt[2] = atoi(intermediate.c_str());   
                                    //cout<< runtimecnt[2] <<endl;
                                }
                                else if(intermediate == "SolutionCost"){
                                    getline(check1,intermediate,':');
                                    solncnt[2] = atoi(intermediate.c_str());
                                    //cout << solncnt[2]<<endl;
                                }
                            }


                            if(lowlevelcnt[0]>lowlevelcnt[2])
                                solnlowlevel[4] ++; // ecbs_2 better than ecbs
                            else if(lowlevelcnt[0]<lowlevelcnt[2])
                                solnlowlevel[0] ++; // ecbs better than ecbs_2

                            
                            if(lowlevelcnt[1]>lowlevelcnt[2])
                                solnlowlevel[5] ++; // ecbs_2 better than ecbs_1
                            else if(lowlevelcnt[1]<lowlevelcnt[2])
                                solnlowlevel[3] ++; // ecbs_1 better than ecbs_2

                            if(lowlevelcnt[0]>lowlevelcnt[1])
                                solnlowlevel[2] ++; // ecbs_1 better than ecbs
                            else if(lowlevelcnt[0]<lowlevelcnt[1])
                                solnlowlevel[1] ++; // ecbs better than ecbs_1

                    
                            if(runtimecnt[0]>runtimecnt[2])
                                solnruntime[4] ++; // ecbs_2 better than ecbs
                            else if(runtimecnt[0]<runtimecnt[2])
                                solnruntime[0] ++; // ecbs better than ecbs_2

                            
                            if(runtimecnt[1]>runtimecnt[2])
                                solnruntime[5] ++; // ecbs_2 better than ecbs_1
                            else if(runtimecnt[1]<runtimecnt[2])
                                solnruntime[3] ++; // ecbs_1 better than ecbs_2

                            if(runtimecnt[0]>runtimecnt[1])
                                solnruntime[2] ++; // ecbs_1 better than ecbs
                            else if(runtimecnt[0]<runtimecnt[1])
                                solnruntime[1] ++; // ecbs better than ecbs_1

                        
                            if(solncnt[0]>solncnt[2])
                                solncost[4] ++; // ecbs_2 better than ecbs
                            else if(solncnt[0]<solncnt[2])
                                solncost[0] ++; // ecbs better than ecbs_2

                            
                            if(solncnt[1]>solncnt[2])
                                solncost[5] ++; // ecbs_2 better than ecbs_1
                            else if(solncnt[1]<solncnt[2])
                                solncost[3] ++; // ecbs_1 better than ecbs_2

                            if(solncnt[0]>solncnt[1])
                                solncost[2] ++; // ecbs_1 better than ecbs
                            else if(solncnt[0]<solncnt[1])
                                solncost[1] ++; // ecbs better than ecbs_1

                        }
                        ex += 1;

                        }
                    // agent += 1;
                    // }

                j += 1;
                }

            cout<< "agent = " << a <<" instances = "  <<  cnt<<endl;  
            cout << "ecbs > ecbs2   ecbs > ecbs1    ecbs1 > ecbs   ecbs1 > ecbs2    ecbs2 > ecbs    ecbs2 > ecbs1" << endl;   
            cout<<"LowLevel: "<<endl;
            for (size_t i = 0; i < 6; i++)
            {
                cout << (solnlowlevel[i]/cnt)*100<< " ";
            }
            cout<<endl<<"runitme: "<<endl;
            for (size_t i = 0; i < 6; i++)
            {
                cout << (solnruntime[i]/cnt)*100<< " ";
            }
            cout<<endl<<"Cost: "<<endl;
            for (size_t i = 0; i < 6; i++)
            {
                cout << (solncost[i]/cnt)*100<< " ";
            }
            cout << endl;
            a += 10;
        }


        break;

    case 5:
        a = 10;
        while(a<101){
            double j = 1.250000000;
            while(j<6){
                double solncnt[6],runtimecnt[6],lowlevelcnt[6],solncost[6],solnruntime[6],solnlowlevel[6];
                for (size_t i = 0; i < 6; i++)
                {
                    solncnt[i]=0,runtimecnt[i]=0,lowlevelcnt[i]=0,solncost[i]=0,solnruntime[i]=0,solnlowlevel[i]=0;
                } 
                int cnt = 0;
                // int agent = 10;  
                // //while(agent<4){
                    int ex = 0;
                    while(ex<10){
                        // string string1 = "/home/mustafizur/pibt/log/8by8_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        // string string2 = "/home/mustafizur/pibt/changed_log/8by8_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        // string string3 = "/home/mustafizur/pibt/changed_changed_log/8by8_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        
                        // string string1 = "/home/mustafizur/pibt/log/32by32_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        // string string2 = "/home/mustafizur/pibt/changed_log/32by32_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        // string string3 = "/home/mustafizur/pibt/changed_changed_log/32by32_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
    


                        string string1 = "/home/mustafizur/pibt/log/warehouse_middle_" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        string string2 = "/home/mustafizur/pibt/changed_log/warehouse_middle_" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        string string3 = "/home/mustafizur/pibt/changed_changed_log/warehouse_middle_" + to_string(ex) + "_" +  to_string(a)+ "_" + to_string(j) + ".txt";

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
                                    //cout << lowlevelcnt[0] <<endl;
                                }
                                else if(intermediate == "[solver] elapsed"){
                                    getline(check1,intermediate,':');
                                    runtimecnt[0] = atoi(intermediate.c_str());   
                                    //cout << runtimecnt[0] <<endl;
                                }
                                else if(intermediate == "SolutionCost"){
                                    getline(check1,intermediate,':');
                                    solncnt[0] = atoi(intermediate.c_str());
                                    //cout << solncnt[0] <<endl;
                                }
                            }
                        
                            while(getline(in2,data)){
                                stringstream check1(data);
                                string intermediate;
                                getline(check1,intermediate,':');
                                if(intermediate == "[solver] Lowlevelnode"){
                                    getline(check1,intermediate,':');
                                    lowlevelcnt[1] = atoi(intermediate.c_str());  
                                    //cout << lowlevelcnt[1] <<endl; 
                                }
                                else if(intermediate == "[solver] elapsed"){
                                    getline(check1,intermediate,':');
                                    runtimecnt[1] = atoi(intermediate.c_str());   
                                    //cout << runtimecnt[1] <<endl;
                                }
                                else if(intermediate == "SolutionCost"){
                                    getline(check1,intermediate,':');
                                    solncnt[1] = atoi(intermediate.c_str());
                                    //cout << solncnt[1] <<endl;
                                }
                            }

                            while(getline(in3,data)){
                                stringstream check1(data);
                                string intermediate;
                                getline(check1,intermediate,':');
                                if(intermediate == "[solver] Lowlevelnode"){
                                    getline(check1,intermediate,':');
                                    lowlevelcnt[2] = atoi(intermediate.c_str()); 
                                    //cout << lowlevelcnt[2] <<endl;  
                                }
                                else if(intermediate == "[solver] elapsed"){
                                    getline(check1,intermediate,':');
                                    runtimecnt[2] = atoi(intermediate.c_str());   
                                    //cout<< runtimecnt[2] <<endl;
                                }
                                else if(intermediate == "SolutionCost"){
                                    getline(check1,intermediate,':');
                                    solncnt[2] = atoi(intermediate.c_str());
                                    //cout << solncnt[2]<<endl;
                                }
                            }


                            if(lowlevelcnt[0]>lowlevelcnt[2])
                                solnlowlevel[4] ++; // ecbs_2 better than ecbs
                            else if(lowlevelcnt[0]<lowlevelcnt[2])
                                solnlowlevel[0] ++; // ecbs better than ecbs_2

                            
                            if(lowlevelcnt[1]>lowlevelcnt[2])
                                solnlowlevel[5] ++; // ecbs_2 better than ecbs_1
                            else if(lowlevelcnt[1]<lowlevelcnt[2])
                                solnlowlevel[3] ++; // ecbs_1 better than ecbs_2

                            if(lowlevelcnt[0]>lowlevelcnt[1])
                                solnlowlevel[2] ++; // ecbs_1 better than ecbs
                            else if(lowlevelcnt[0]<lowlevelcnt[1])
                                solnlowlevel[1] ++; // ecbs better than ecbs_1

                    
                            if(runtimecnt[0]>runtimecnt[2])
                                solnruntime[4] ++; // ecbs_2 better than ecbs
                            else if(runtimecnt[0]<runtimecnt[2])
                                solnruntime[0] ++; // ecbs better than ecbs_2

                            
                            if(runtimecnt[1]>runtimecnt[2])
                                solnruntime[5] ++; // ecbs_2 better than ecbs_1
                            else if(runtimecnt[1]<runtimecnt[2])
                                solnruntime[3] ++; // ecbs_1 better than ecbs_2

                            if(runtimecnt[0]>runtimecnt[1])
                                solnruntime[2] ++; // ecbs_1 better than ecbs
                            else if(runtimecnt[0]<runtimecnt[1])
                                solnruntime[1] ++; // ecbs better than ecbs_1

                        
                            if(solncnt[0]>solncnt[2])
                                solncost[4] ++; // ecbs_2 better than ecbs
                            else if(solncnt[0]<solncnt[2])
                                solncost[0] ++; // ecbs better than ecbs_2

                            
                            if(solncnt[1]>solncnt[2])
                                solncost[5] ++; // ecbs_2 better than ecbs_1
                            else if(solncnt[1]<solncnt[2])
                                solncost[3] ++; // ecbs_1 better than ecbs_2

                            if(solncnt[0]>solncnt[1])
                                solncost[2] ++; // ecbs_1 better than ecbs
                            else if(solncnt[0]<solncnt[1])
                                solncost[1] ++; // ecbs better than ecbs_1

                        }
                        ex += 1;

                        }
                    // agent += 1;
                    // }
                    cout<< "agent = " << a << " weight = " << j << " instances = "  <<  cnt<<endl;  
                    cout << "ecbs > ecbs2   ecbs > ecbs1    ecbs1 > ecbs   ecbs1 > ecbs2    ecbs2 > ecbs    ecbs2 > ecbs1" << endl;   
                    cout<<"LowLevel: "<<endl;
                    for (size_t i = 0; i < 6; i++)
                    {
                        cout << (solnlowlevel[i]/cnt)*100<< " ";
                    }
                    cout<<endl<<"runitme: "<<endl;
                    for (size_t i = 0; i < 6; i++)
                    {
                        cout << (solnruntime[i]/cnt)*100<< " ";
                    }
                    cout<<endl<<"Cost: "<<endl;
                    for (size_t i = 0; i < 6; i++)
                    {
                        cout << (solncost[i]/cnt)*100<< " ";
                    }
                    cout << endl;

                j += 1;
                }
            a += 10;
        }

        break;

    case 6:

        j = 1.250000000;
        while(j<6){ 
            a = 10;
            int cnt = 0;
                double solncnt[6],runtimecnt[6],lowlevelcnt[6],solncost[6],solnruntime[6],solnlowlevel[6];
                for (size_t i = 0; i < 6; i++)
                {
                    solncnt[i]=0,runtimecnt[i]=0,lowlevelcnt[i]=0,solncost[i]=0,solnruntime[i]=0,solnlowlevel[i]=0;
                } 
            while(a<101){
            //while(j<6){
                // int agent = 10;  
                // //while(agent<4){
                    int ex = 0;
                    while(ex<10){
                        // string string1 = "/home/mustafizur/pibt/log/8by8_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        // string string2 = "/home/mustafizur/pibt/changed_log/8by8_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        // string string3 = "/home/mustafizur/pibt/changed_changed_log/8by8_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        
                        // string string1 = "/home/mustafizur/pibt/log/32by32_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        // string string2 = "/home/mustafizur/pibt/changed_log/32by32_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        // string string3 = "/home/mustafizur/pibt/changed_changed_log/32by32_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
    


                        string string1 = "/home/mustafizur/pibt/log/warehouse_middle_" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        string string2 = "/home/mustafizur/pibt/changed_log/warehouse_middle_" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        string string3 = "/home/mustafizur/pibt/changed_changed_log/warehouse_middle_" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";

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
                                    //cout << lowlevelcnt[0] <<endl;
                                }
                                else if(intermediate == "[solver] elapsed"){
                                    getline(check1,intermediate,':');
                                    runtimecnt[0] = atoi(intermediate.c_str());   
                                    //cout << runtimecnt[0] <<endl;
                                }
                                else if(intermediate == "SolutionCost"){
                                    getline(check1,intermediate,':');
                                    solncnt[0] = atoi(intermediate.c_str());
                                    //cout << solncnt[0] <<endl;
                                }
                            }
                        
                            while(getline(in2,data)){
                                stringstream check1(data);
                                string intermediate;
                                getline(check1,intermediate,':');
                                if(intermediate == "[solver] Lowlevelnode"){
                                    getline(check1,intermediate,':');
                                    lowlevelcnt[1] = atoi(intermediate.c_str());  
                                    //cout << lowlevelcnt[1] <<endl; 
                                }
                                else if(intermediate == "[solver] elapsed"){
                                    getline(check1,intermediate,':');
                                    runtimecnt[1] = atoi(intermediate.c_str());   
                                    //cout << runtimecnt[1] <<endl;
                                }
                                else if(intermediate == "SolutionCost"){
                                    getline(check1,intermediate,':');
                                    solncnt[1] = atoi(intermediate.c_str());
                                    //cout << solncnt[1] <<endl;
                                }
                            }

                            while(getline(in3,data)){
                                stringstream check1(data);
                                string intermediate;
                                getline(check1,intermediate,':');
                                if(intermediate == "[solver] Lowlevelnode"){
                                    getline(check1,intermediate,':');
                                    lowlevelcnt[2] = atoi(intermediate.c_str()); 
                                    //cout << lowlevelcnt[2] <<endl;  
                                }
                                else if(intermediate == "[solver] elapsed"){
                                    getline(check1,intermediate,':');
                                    runtimecnt[2] = atoi(intermediate.c_str());   
                                    //cout<< runtimecnt[2] <<endl;
                                }
                                else if(intermediate == "SolutionCost"){
                                    getline(check1,intermediate,':');
                                    solncnt[2] = atoi(intermediate.c_str());
                                    //cout << solncnt[2]<<endl;
                                }
                            }

                            if(lowlevelcnt[2]==0){
                                solnlowlevel[0] += 1;
                                solnlowlevel[1] += 1;
                            }
                            else{
                                solnlowlevel[0] += lowlevelcnt[0]/lowlevelcnt[2];
                                solnlowlevel[1] += lowlevelcnt[1]/lowlevelcnt[2];
                            }

                            if(lowlevelcnt[1]==0){
                                solnlowlevel[2] += 1;
                            }
                            else{
                                solnlowlevel[2] += lowlevelcnt[0]/lowlevelcnt[1];
                            }

                            if(runtimecnt[2]==0){
                                solnruntime[0] += 1;
                                solnruntime[1] += 1;
                            }
                            else{
                                solnruntime[0] += runtimecnt[0]/runtimecnt[2];
                                solnruntime[1] += runtimecnt[1]/runtimecnt[2];
                            }

                            if(runtimecnt[1]==0){
                                solnruntime[2] += 1;
                            }
                            else{
                                solnruntime[2] += runtimecnt[0]/runtimecnt[1];
                            }

                            if(solncnt[2]==0){
                                solncost[0] += 1;
                                solncost[1] += 1;
                            }
                            else{
                                solncost[0] += solncnt[0]/solncnt[2]; 
                                solncost[1] += solncnt[1]/solncnt[2];
                            }

                            if(solncnt[1]==0){
                                solncost[2] += 1;
                            }
                            else{
                                solncost[2] += solncnt[0]/solncnt[1];
                            }
                        }
                        ex += 1;

                        }
                    // agent += 1;
                    // }

                a += 10;
                }

            cout << "ecbs/ecbs_1    ecbs/ecbs_2    ecbs_1/ecbs_2" << endl;
            cout<< " weight = " << j <<" instances = "  <<  cnt<<endl;
            cout << "Lowlevel: "<< solnlowlevel[2]/cnt << " " << solnlowlevel[0]/cnt << " " << solnlowlevel[1]/cnt << endl;
            cout << "runtime: " << solnruntime[2]/cnt << " " << solnruntime[0]/cnt << " " << solnruntime[1]/cnt <<endl;
            cout << "Cost: " << solncost[2]/cnt << " " << solncost[0]/cnt << " " << solncost[1]/cnt << endl;
            j += 1;
            }

        break;
    
    case 7:
        a = 10;
        while(a<101){
            j = 1.250000000;
            int cnt = 0;
            double solncnt[6],runtimecnt[6],lowlevelcnt[6],solncost[6],solnruntime[6],solnlowlevel[6];
            for (size_t i = 0; i < 6; i++)
            {
                solncnt[i]=0,runtimecnt[i]=0,lowlevelcnt[i]=0,solncost[i]=0,solnruntime[i]=0,solnlowlevel[i]=0;
            } 
            while(j<6){
                // int agent = 10;  
                // //while(agent<4){
                    int ex = 0;
                    while(ex<10){
                        // string string1 = "/home/mustafizur/pibt/log/8by8_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        // string string2 = "/home/mustafizur/pibt/changed_log/8by8_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        // string string3 = "/home/mustafizur/pibt/changed_changed_log/8by8_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        
                        // string string1 = "/home/mustafizur/pibt/log/32by32_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        // string string2 = "/home/mustafizur/pibt/changed_log/32by32_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        // string string3 = "/home/mustafizur/pibt/changed_changed_log/32by32_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
    


                        string string1 = "/home/mustafizur/pibt/log/warehouse_middle_" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        string string2 = "/home/mustafizur/pibt/changed_log/warehouse_middle_" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        string string3 = "/home/mustafizur/pibt/changed_changed_log/warehouse_middle_" + to_string(ex) + "_" +  to_string(a)+ "_" + to_string(j) + ".txt";

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
                                    //cout << lowlevelcnt[0] <<endl;
                                }
                                else if(intermediate == "[solver] elapsed"){
                                    getline(check1,intermediate,':');
                                    runtimecnt[0] = atoi(intermediate.c_str());   
                                    //cout << runtimecnt[0] <<endl;
                                }
                                else if(intermediate == "SolutionCost"){
                                    getline(check1,intermediate,':');
                                    solncnt[0] = atoi(intermediate.c_str());
                                    //cout << solncnt[0] <<endl;
                                }
                            }
                        
                            while(getline(in2,data)){
                                stringstream check1(data);
                                string intermediate;
                                getline(check1,intermediate,':');
                                if(intermediate == "[solver] Lowlevelnode"){
                                    getline(check1,intermediate,':');
                                    lowlevelcnt[1] = atoi(intermediate.c_str());  
                                    //cout << lowlevelcnt[1] <<endl; 
                                }
                                else if(intermediate == "[solver] elapsed"){
                                    getline(check1,intermediate,':');
                                    runtimecnt[1] = atoi(intermediate.c_str());   
                                    //cout << runtimecnt[1] <<endl;
                                }
                                else if(intermediate == "SolutionCost"){
                                    getline(check1,intermediate,':');
                                    solncnt[1] = atoi(intermediate.c_str());
                                    //cout << solncnt[1] <<endl;
                                }
                            }

                            while(getline(in3,data)){
                                stringstream check1(data);
                                string intermediate;
                                getline(check1,intermediate,':');
                                if(intermediate == "[solver] Lowlevelnode"){
                                    getline(check1,intermediate,':');
                                    lowlevelcnt[2] = atoi(intermediate.c_str()); 
                                    //cout << lowlevelcnt[2] <<endl;  
                                }
                                else if(intermediate == "[solver] elapsed"){
                                    getline(check1,intermediate,':');
                                    runtimecnt[2] = atoi(intermediate.c_str());   
                                    //cout<< runtimecnt[2] <<endl;
                                }
                                else if(intermediate == "SolutionCost"){
                                    getline(check1,intermediate,':');
                                    solncnt[2] = atoi(intermediate.c_str());
                                    //cout << solncnt[2]<<endl;
                                }
                            }

                            if(lowlevelcnt[2]==0){
                                solnlowlevel[0] += 1;
                                solnlowlevel[1] += 1;
                            }
                            else{
                                solnlowlevel[0] += lowlevelcnt[0]/lowlevelcnt[2];
                                solnlowlevel[1] += lowlevelcnt[1]/lowlevelcnt[2];
                            }

                            if(lowlevelcnt[1]==0){
                                solnlowlevel[2] += 1;
                            }
                            else{
                                solnlowlevel[2] += lowlevelcnt[0]/lowlevelcnt[1];
                            }

                            if(runtimecnt[2]==0){
                                solnruntime[0] += 1;
                                solnruntime[1] += 1;
                            }
                            else{
                                solnruntime[0] += runtimecnt[0]/runtimecnt[2];
                                solnruntime[1] += runtimecnt[1]/runtimecnt[2];
                            }

                            if(runtimecnt[1]==0){
                                solnruntime[2] += 1;
                            }
                            else{
                                solnruntime[2] += runtimecnt[0]/runtimecnt[1];
                            }

                            if(solncnt[2]==0){
                                solncost[0] += 1;
                                solncost[1] += 1;
                            }
                            else{
                                solncost[0] += solncnt[0]/solncnt[2]; 
                                solncost[1] += solncnt[1]/solncnt[2];
                            }

                            if(solncnt[1]==0){
                                solncost[2] += 1;
                            }
                            else{
                                solncost[2] += solncnt[0]/solncnt[1];
                            }
                        }
                        ex += 1;

                        }
                    // agent += 1;
                    // }

                j += 1;
                }

            cout << "ecbs/ecbs_1    ecbs/ecbs_2    ecbs_1/ecbs_2" << endl;
            cout<< " agent = " << a <<" instances = "  <<  cnt<<endl;
            cout << "Lowlevel: "<< solnlowlevel[2]/cnt << " " << solnlowlevel[0]/cnt << " " << solnlowlevel[1]/cnt << endl;
            cout << "runtime: " << solnruntime[2]/cnt << " " << solnruntime[0]/cnt << " " << solnruntime[1]/cnt <<endl;
            cout << "Cost: " << solncost[2]/cnt << " " << solncost[0]/cnt << " " << solncost[1]/cnt << endl;
            a += 10;
            }

        break;

    case 8:
        a = 10;
        while(a<101){
            j = 1.250000000;
            while(j<6){
                    int cnt = 0;
                    double solncnt[6],runtimecnt[6],lowlevelcnt[6],solncost[6],solnruntime[6],solnlowlevel[6];
                    for (size_t i = 0; i < 6; i++)
                    {
                        solncnt[i]=0,runtimecnt[i]=0,lowlevelcnt[i]=0,solncost[i]=0,solnruntime[i]=0,solnlowlevel[i]=0;
                    } 
                // int agent = 10;  
                // //while(agent<4){
                    int ex = 0;
                    while(ex<10){
                        // string string1 = "/home/mustafizur/pibt/log/8by8_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        // string string2 = "/home/mustafizur/pibt/changed_log/8by8_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        // string string3 = "/home/mustafizur/pibt/changed_changed_log/8by8_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        
                        // string string1 = "/home/mustafizur/pibt/log/32by32_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        // string string2 = "/home/mustafizur/pibt/changed_log/32by32_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        // string string3 = "/home/mustafizur/pibt/changed_changed_log/32by32_agents" + to_string(agent) + "_ex" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
    


                        string string1 = "/home/mustafizur/pibt/log/warehouse_middle_" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";
                        string string2 = "/home/mustafizur/pibt/changed_log/warehouse_middle_" + to_string(ex) + "_" +to_string(a)+ "_" + to_string(j) + ".txt";
                        string string3 = "/home/mustafizur/pibt/changed_changed_log/warehouse_middle_" + to_string(ex) + "_" + to_string(a)+ "_" + to_string(j) + ".txt";

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
                                    //cout << lowlevelcnt[0] <<endl;
                                }
                                else if(intermediate == "[solver] elapsed"){
                                    getline(check1,intermediate,':');
                                    runtimecnt[0] = atoi(intermediate.c_str());   
                                    //cout << runtimecnt[0] <<endl;
                                }
                                else if(intermediate == "SolutionCost"){
                                    getline(check1,intermediate,':');
                                    solncnt[0] = atoi(intermediate.c_str());
                                    //cout << solncnt[0] <<endl;
                                }
                            }
                        
                            while(getline(in2,data)){
                                stringstream check1(data);
                                string intermediate;
                                getline(check1,intermediate,':');
                                if(intermediate == "[solver] Lowlevelnode"){
                                    getline(check1,intermediate,':');
                                    lowlevelcnt[1] = atoi(intermediate.c_str());  
                                    //cout << lowlevelcnt[1] <<endl; 
                                }
                                else if(intermediate == "[solver] elapsed"){
                                    getline(check1,intermediate,':');
                                    runtimecnt[1] = atoi(intermediate.c_str());   
                                    //cout << runtimecnt[1] <<endl;
                                }
                                else if(intermediate == "SolutionCost"){
                                    getline(check1,intermediate,':');
                                    solncnt[1] = atoi(intermediate.c_str());
                                    //cout << solncnt[1] <<endl;
                                }
                            }

                            while(getline(in3,data)){
                                stringstream check1(data);
                                string intermediate;
                                getline(check1,intermediate,':');
                                if(intermediate == "[solver] Lowlevelnode"){
                                    getline(check1,intermediate,':');
                                    lowlevelcnt[2] = atoi(intermediate.c_str()); 
                                    //cout << lowlevelcnt[2] <<endl;  
                                }
                                else if(intermediate == "[solver] elapsed"){
                                    getline(check1,intermediate,':');
                                    runtimecnt[2] = atoi(intermediate.c_str());   
                                    //cout<< runtimecnt[2] <<endl;
                                }
                                else if(intermediate == "SolutionCost"){
                                    getline(check1,intermediate,':');
                                    solncnt[2] = atoi(intermediate.c_str());
                                    //cout << solncnt[2]<<endl;
                                }
                            }

                            if(lowlevelcnt[2]==0){
                                solnlowlevel[0] += 1;
                                solnlowlevel[1] += 1;
                            }
                            else{
                                solnlowlevel[0] += lowlevelcnt[0]/lowlevelcnt[2];
                                solnlowlevel[1] += lowlevelcnt[1]/lowlevelcnt[2];
                            }

                            if(lowlevelcnt[1]==0){
                                solnlowlevel[2] += 1;
                            }
                            else{
                                solnlowlevel[2] += lowlevelcnt[0]/lowlevelcnt[1];
                            }

                            if(runtimecnt[2]==0){
                                solnruntime[0] += 1;
                                solnruntime[1] += 1;
                            }
                            else{
                                solnruntime[0] += runtimecnt[0]/runtimecnt[2];
                                solnruntime[1] += runtimecnt[1]/runtimecnt[2];
                            }

                            if(runtimecnt[1]==0){
                                solnruntime[2] += 1;
                            }
                            else{
                                solnruntime[2] += runtimecnt[0]/runtimecnt[1];
                            }

                            if(solncnt[2]==0){
                                solncost[0] += 1;
                                solncost[1] += 1;
                            }
                            else{
                                solncost[0] += solncnt[0]/solncnt[2]; 
                                solncost[1] += solncnt[1]/solncnt[2];
                            }

                            if(solncnt[1]==0){
                                solncost[2] += 1;
                            }
                            else{
                                solncost[2] += solncnt[0]/solncnt[1];
                            }
                        }
                        ex += 1;

                        }
                    // agent += 1;
                    // }

                cout << "ecbs/ecbs_1    ecbs/ecbs_2    ecbs_1/ecbs_2" << endl;
                cout<< " agent = " << a << " weight = " << j << " instances = "  <<  cnt<<endl;
                cout << "Lowlevel: "<< solnlowlevel[2]/cnt << " " << solnlowlevel[0]/cnt << " " << solnlowlevel[1]/cnt << endl;
                cout << "runtime: " << solnruntime[2]/cnt << " " << solnruntime[0]/cnt << " " << solnruntime[1]/cnt <<endl;
                cout << "Cost: " << solncost[2]/cnt << " " << solncost[0]/cnt << " " << solncost[1]/cnt << endl;

                j += 1;
                }
            a += 10;
            }

        break;
    } 
    return 0;
}