

// 2. Insert function:
template <class data, class key>
bool T_HMap<data, key>::insert(const data& inData, const key& inKey){

  // Compute the index using the hash function:
  size_t idx = this->hash_func(inKey);

  // Case A: No collision:
  if (hash_table.at(idx) == NULL){

      hash_table.at(idx) = new H_elem<data>(inData);

      return true;

  }

  // Case B: Collision:
  else{

    hash_table.at(idx)->next = new H_elem<data>(inData);

    return true;
  }

  return false;

}

// 3. Find function:
template <class data, class key>
bool T_HMap <data, key>::retrieve(const key& findKey, data& outData){

  size_t idx = hash_func(findKey);

  if (hash_table.at(idx) != NULL){
    outData = hash_table.at(idx)->H_data;
    return true;
  }
  else{
    return false;
  }
}
