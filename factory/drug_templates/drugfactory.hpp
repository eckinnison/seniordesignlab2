#include <string>

class DrugFactory{

	public:
		virtual Drug* makeDrug() = 0; // VIRTUAL factory method- lets your subclass define how something is produced
		virtual shipDrug() = 0; // Make sure there's a way to update the drug warehouse
	
	private:
		std::string drug_warehouse_path;
	
};
