#include <iostream>
#include <fstream>
#include <string>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main()
{
    std::string filename = "qlogicae/configurations/qlogicae.public.json"; 
    std::ifstream file(filename);

    json j = json::parse(file);
    std::string environment_selected = j.at("environment").at("selected").get<std::string>();
    std::string environment_selections_id = j.at("environment").at("selections").at(environment_selected).get<std::string>();

    std::cout << "environment.selected: " << environment_selected << "\n";
    std::cout << "environment.selections id: " << environment_selections_id << "\n";

    return 0;
}
