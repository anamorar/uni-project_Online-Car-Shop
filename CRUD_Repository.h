#ifndef CRUD_REPOSITORY_H
#define CRUD_REPOSITORY_H
#include "MainHeader.h"


/**
* CREATE, READ, UPDATE, DELETE
* CRUD operations repository interface
*/
template <class E>
class CrudRepository
{
public:
    /**
    * @param id -the id of the entity to be returned id must not be null
    * @return the entity with the specified id or null - if there is no entity with the given id
    *
    */
    virtual E findOne(int id) = 0;

    /**
    * @return all entities
    */
    virtual vector<E> findAll() = 0;

    /**
    * @param entity entity must be not null
    * @return null- if the given entity is saved otherwise returns the entity (id already exists)
    *
    */
    virtual E save(E entity) = 0;

    /**
    * removes the entity with the specified id
    *
    * @param id id must be not null
    * @return the removed entity or null if there is no entity with the given id
    *
    */
    virtual E del(int id) = 0;

    /**
    * @param entity entity must not be null
    * @return null - if the entity is updated, otherwise returns the entity - (e.g id does not exist).
    *
    */
    virtual E update(E entity) = 0;

    virtual ~CrudRepository(){};
};

#endif
