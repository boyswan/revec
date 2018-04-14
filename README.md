## Revec

Vector utilities to add, 

Example

```reason
let foo = [3, 9];
let bar = [1, 7];

Revec.add(foo, bar);

/*log: [4, 16] */
```

```reason
open Revec;
open Revec.Pervasives;

let foo = (5, 6 ,7) |> list_of_tuple3;
let bar = (2, 5, 9) |> list_of_tuple3;

foo *^ bar

/*log: [10, 30, 63] */
```
