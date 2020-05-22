#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cstdlib>
#include <fstream>
#include "../tables/tscantable.h"
#include "../tables/tsorttable.h"
#include "../tables/tbalancetree.h"
#include "../tables/tarrayhash.h"
#include "../tables/tlisthash.h"
#include "../tables/ttreetable.h"

using namespace std;

int main() {

	vector<string> sur(20);
	TScanTable scan_table;
	TSortTable sort_table;
	TTreeTable tree_table;
	TBalanceTree btree_table;
	TArrayHash ahash_table;
	TListHash lhash_table;
	ifstream in("D:\\Projects\\C++\\lab8\\sample\\input.txt");
	if (!in.is_open()) return 0;
	int size = 10;
	for (int i = 0; i < size; ++i) {
		string s;
		getline(in, s, '\n');
		cout << s << endl;
		sur.push_back(s);
		scan_table.InsRecord(s, nullptr);
		sort_table.InsRecord(s, nullptr);
		tree_table.InsRecord(s, nullptr);
		btree_table.InsRecord(s, nullptr);
		ahash_table.InsRecord(s, nullptr);
		lhash_table.InsRecord(s, nullptr);
	}
	in.close();

	cout << "Insert:" << endl;
	cout << "scan_table: " << scan_table.GetEfficiency() << endl;
	cout << "sort_table: " << sort_table.GetEfficiency() << endl;
	cout << "tree_table: " << tree_table.GetEfficiency() << endl;
	cout << "btree_table: " << btree_table.GetEfficiency() << endl;
	cout << "ahash_table: " << ahash_table.GetEfficiency() << endl;
	cout << "lhash_table: " << lhash_table.GetEfficiency() << endl;

	scan_table.ResetEfficiency();
	sort_table.ResetEfficiency();
	tree_table.ResetEfficiency();
	btree_table.ResetEfficiency();
	ahash_table.ResetEfficiency();
	lhash_table.ResetEfficiency();

	for (int i = 0; i < size; ++i) {
		scan_table.FindRecord(sur[i]);
		sort_table.FindRecord(sur[i]);
		tree_table.FindRecord(sur[i]);
		btree_table.FindRecord(sur[i]);
		ahash_table.FindRecord(sur[i]);
		lhash_table.FindRecord(sur[i]);
	}

	cout << "Find: " << endl;
	cout << "scan_table: " << scan_table.GetEfficiency() << endl;
	cout << "sort_table: " << sort_table.GetEfficiency() << endl;
	cout << "tree_table: " << tree_table.GetEfficiency() << endl;
	cout << "btree_table: " << btree_table.GetEfficiency() << endl;
	cout << "ahash_table: " << ahash_table.GetEfficiency() << endl;
	cout << "lhash_table: " << lhash_table.GetEfficiency() << endl;

	scan_table.ResetEfficiency();
	sort_table.ResetEfficiency();
	tree_table.ResetEfficiency();
	btree_table.ResetEfficiency();
	ahash_table.ResetEfficiency();
	lhash_table.ResetEfficiency();
	for (int i = 0; i < size; i++) {
		scan_table.DelRecord(sur[i]);
		sort_table.DelRecord(sur[i]);
		tree_table.DelRecord(sur[i]);
		btree_table.DelRecord(sur[i]);
		ahash_table.DelRecord(sur[i]);
		lhash_table.DelRecord(sur[i]);
	}
	cout << "Delete: " << endl;
	cout << "scan_table: " << scan_table.GetEfficiency() << endl;
	cout << "sort_table: " << sort_table.GetEfficiency() << endl;
	cout << "tree_table: " << tree_table.GetEfficiency() << endl;
	cout << "btree_table: " << btree_table.GetEfficiency() << endl;
	cout << "ahash_table: " << ahash_table.GetEfficiency() << endl;
	cout << "lhash_table: " << lhash_table.GetEfficiency() << endl;

	return 0;
}