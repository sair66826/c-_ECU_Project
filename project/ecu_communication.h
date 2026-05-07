#ifndef ECU_COMMUNICATION_H
#define ECU_COMMUNICATION_H
 
#include <string>
#include <vector>
#include <unordered_map>
#include<unordered_set>
 
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define VIOLET  "\033[95m"
#define PINK    "\033[95m"
#define BOLD    "\033[1m"
#define YELLOW "\033[33m"
#define ORANGE "\033[38;5;208m"

class ecu_communication {

    struct communication_link {
       std::string unit1, unit2;
        double delay, link_cost;
    };

    double a,b,c;
    double ts_cost = 0, tp_delay = 0;

   std::vector<communication_link> link;
   std::vector<communication_link> mst_link;

   std::unordered_map<std::string,std::string> parent;
   std::unordered_map<std::string,int> rank;
    
   std::unordered_set<std::string> activeNodes;

   std::unordered_map<int,std::string> m = {
        {0,"Engine Control Unit"},
        {1,"Brake Control Unit"},
        {2,"Steering Control Unit"},
        {3,"ADAS Processing Unit"},
        {4,"Battery Management System"},
        {5,"Infotainment Control Unit"}
    };

public:
    ecu_communication();

    ecu_communication(const ecu_communication&);  

private:

    // -------- COST ENGINE --------
   std:: pair<double,double> cost_computation_engine();  
   
       void availableecus();
       void availablecables();

    // -------- HARDWARE INPUT --------
    void hardware_modelling();  
    // -------- PRINT COMPONENTS --------
    void print_connected_components();
    void reset_mst(); 
    // -------- KRUSKAL --------
    void optimization_engine();  
 

    // -------- DSU --------
   std:: string find_parent(std::string ); 
    void union_set(std::string ,std::string ); 
    int getIndex(const std::string &); 
    void run_dijkstra(); 
    void add_ecu();
    void print_mst_links();
    void print_all_links();
public:
    void hardware_init();
    void optimization_init();
    void dijkstra();
    
    void architecture_menu(); 
    ~ecu_communication();
};

#endif
 
