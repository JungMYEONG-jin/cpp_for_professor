```rust
use std::collections::BTreeMap;

impl Solution {
    
    pub fn restore_string(s: String, indices: Vec<i32>) -> String {
        let mut db = BTreeMap::new();
        let len = s.len() as i32;
        for i in 0..len{
            db.insert(indices[i as usize], s.as_bytes()[i as usize] as char);
        };
        let mut result = String::new();
        for key in db.keys(){
            result.push(*db.get(key).unwrap()); // &char to char
        };
        return result;
    }
}

```
