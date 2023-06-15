#include <iostream>
#include <unordered_map>

using namespace std;

enum MenuName {
    EGG_MAYO = 0,
    ITALIAN_BMT,
    BLT,
    HAM,
    TUNA
};

enum MenuName {
    cheese = 0,
    bread,
    vegetable,
    pepperoni,
    eggMayo,
    tuna,
    salami
};

• cheese : 200
• bread, vegetable, pepperoni : 300 • eggMayo, tuna : 400
• salami : 700

int ingredients

class SandwichShop {
private:
    std::unordered_map<std::string, int> inventory;
    std::unordered_map<std::string, int> prices;
    int revenue;

public:
    SandwichShop() {
        inventory = {
            {"eggMayo", 100},
            {"cheese", 100},
            {"vegetable", 100},
            {"bread", 100},
            {"pepperoni", 100},
            {"salami", 100},
            {"ham", 100},
            {"bacon", 100},
            {"tuna", 100}
        };

        prices = {
            {"cheese", 200},
            {"bread", 300},
            {"vegetable", 300},
            {"pepperoni", 300},
            {"eggMayo", 400},
            {"tuna", 400},
            {"salami", 700}
        };

        revenue = 0;
    }

    void processOrder(MenuName menu) {
        std::unordered_map<std::string, int> menuIngredients;
        int menuPrice;

        switch (menu) {
            case EGG_MAYO:
                menuIngredients = {{"eggMayo", 2}, {"cheese", 2}, {"vegetable", 1}, {"bread", 1}};
                menuPrice = 5500;
                break;
            case ITALIAN_BMT:
                menuIngredients = {{"pepperoni", 2}, {"salami", 3}, {"ham", 2}, {"cheese", 2}, {"vegetable", 1}, {"bread", 1}};
                menuPrice = 6700;
                break;
            case BLT:
                menuIngredients = {{"bacon", 4}, {"cheese", 2}, {"vegetable", 1}, {"bread", 1}};
                menuPrice = 6600;
                break;
            case HAM:
                menuIngredients = {{"ham", 4}, {"cheese", 2}, {"vegetable", 1}, {"bread", 1}};
                menuPrice = 5800;
                break;
            case TUNA:
                menuIngredients = {{"tuna", 2}, {"cheese", 2}, {"vegetable", 1}, {"bread", 1}};
                menuPrice = 5800;
                break;
            default:
                std::cout << "Invalid menu\n";
                return;
        }

        // Check ingredient availability
        bool ingredientsAvailable = true;
        for (const auto& ingredient : menuIngredients) {
            if (inventory[ingredient.first] < ingredient.second) {
                ingredientsAvailable = false;
                break;
            }
        }

        if (!ingredientsAvailable) {
            refillIngredients();
            std::cout << "Ingredients refilled\n";
        }

        // Process the order
        bool orderCompleted = true;
        for (const auto& ingredient : menuIngredients) {
            if (inventory[ingredient.first] >= ingredient.second) {
                inventory[ingredient.first] -= ingredient.second;
            } else {
                orderCompleted = false;
                break;
            }
        }

        if (orderCompleted) {
            revenue += menuPrice - calculateCost(menuIngredients);
            std::cout << "Order processed\n";
        } else {
            std::cout << "Insufficient ingredients to complete the order\n";
        }
    }

    void refillIngredients() {
        for (auto& ingredient : inventory) {
            ingredient.second += 100;
        }
    }

    int calculateCost(const std::unordered_map<std::string, int>& ingredients) {
        int cost = 0;
        for (const auto& ingredient : ingredients) {
            cost += ingredient.second * prices[ingredient.first];
        }
        return cost;
    }

    int getTotalRevenue() {
        return revenue;
    }
};

int main() {
    SandwichShop shop;

    // Process orders
    shop.processOrder(MenuName::TUNA);
    shop.processOrder(MenuName::BLT);
    shop.processOrder(MenuName::ITALIAN_BMT);
    shop.processOrder(MenuName::EGG_MAYO);
    shop.processOrder(MenuName::HAM);

    // Get total revenue
    int totalRevenue = shop.getTotalRevenue();
    std::cout << "Total Revenue: " << totalRevenue << "\n";

    return 0;
}
