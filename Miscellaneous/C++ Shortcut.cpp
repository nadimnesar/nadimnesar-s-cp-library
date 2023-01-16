#define remove_all_index_value_y(x,y)		x.erase(remove(x.begin(),x.end(),y),x.end())
#define remove_ith_index(x,y)				x.erase(x.begin()+y)
#define case								cout << "Case " << ++cn << ": ";