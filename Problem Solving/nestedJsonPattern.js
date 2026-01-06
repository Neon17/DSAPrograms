var obj = {
    a: 1,
    b: {
        c: 2,
    },
    c: {
        d: {
            e: {
                f: 3,
            }
        }
    },
};

var arr = { ...obj };
var keys = Object.keys(obj);

let newObject = {};

for (const keys in obj){
    if ((typeof(obj[keys]))=='object'){
        var newValue = obj[keys];
        var newKey = keys;
        do{
            if (typeof(newValue)=='object'){
                let key = Object.keys(newValue)[0];
                newValue = newValue[key];
                newKey += `_${key}`;           
            }
        } while(typeof(newValue)=='object');
        newObject[newKey] = newValue;
        continue;
    }
    newObject[keys] = obj[keys];
}
console.log(newObject);

// let obj = {
//     a: 1,
//     b_c: 2,
//     c_d_e_f: 3,
// }

