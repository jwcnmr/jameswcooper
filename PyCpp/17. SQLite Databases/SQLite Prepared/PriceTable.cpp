<<<<<<< HEAD
#include "PriceTable.h"

PriceTable::PriceTable (sqltDatabase sqldb) : Table("prices", sqldb){
	addColumn(new PrimaryCol("pricekey"));
	addColumn(new IntCol("foodkey"));
	addColumn(new IntCol("storekey"));
	addColumn(new FloatCol("price"));
	create();
}

int PriceTable::addRow( pricetuple ptuple) {
		string sql = "insert into " + tbName;
		sql += " (storekey, foodkey, price) ";
		sql += "values (" ;
		int fkey;
		int skey;
		float price;
		std::tie(fkey, skey, price) = ptuple;
		sql += to_string(fkey) + ",";
		sql += to_string(skey) + ",";
		sql += to_string(price) ;
		sql += ")";
		sqltQuery qry(db, sql);
		qry.execute();
		return 0;
	}
=======
#include "PriceTable.h"

PriceTable::PriceTable (sqltDatabase sqldb) : Table("prices", sqldb){
	addColumn(new PrimaryCol("pricekey"));
	addColumn(new IntCol("foodkey"));
	addColumn(new IntCol("storekey"));
	addColumn(new FloatCol("price"));
	create();
}

int PriceTable::addRow( pricetuple ptuple) {
		string sql = "insert into " + tbName;
		sql += " (storekey, foodkey, price) ";
		sql += "values (" ;
		int fkey;
		int skey;
		float price;
		std::tie(fkey, skey, price) = ptuple;
		sql += to_string(fkey) + ",";
		sql += to_string(skey) + ",";
		sql += to_string(price) ;
		sql += ")";
		sqltQuery qry(db, sql);
		qry.execute();
		return 0;
	}
>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
