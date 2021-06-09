/*
* CRUD operations repository interface
*/
template <class E>
class CrudRepository
{
public:

    virtual int search_id(int id) = 0;

    virtual vector<E> const get_Liste() = 0;

    virtual int search(E entity) = 0;

    virtual bool loschen_auto(int id) = 0;

    virtual ~CrudRepository(){};
};