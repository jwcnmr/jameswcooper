#include "globaldefs.h"
#include "PriceTable.h"
#include "msqDatabase.h"

PriceTable::PriceTable (msqDatabase* msqdb) : msqTable("prices", msqdb){
	addColumn(new PrimaryCol("pricekey"));
	addColumn(new IntCol("foodkey"));
	addColumn(new IntCol("storekey"));
	addColumn(new FloatCol("price"));
	create();
}

//adds a row to the pricetable
int PriceTable::addRow( pricetuple ptuple) {
		string sql = "insert into " + tbName;
		sql += " (storekey, foodkey, price) ";
		sql += "values (" ;
		int fkey; int skey; float price;
		//unpack tuple into 3 variables
		std::tie(fkey, skey, price) = ptuple;
		sql += to_string(fkey) + ",";
		sql += to_string(skey) + ",";
		sql += to_string(price) ;
		sql += ")";
		Query qry(db, sql);
		qry.execute();
		return 0;
	}
