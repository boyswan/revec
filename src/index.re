let opVec = fn =>
  fun
  | ([a, b], [c]) => [fn(a, c), fn(b, c)]
  | ([a, b], [c, d]) => [fn(a, c), fn(b, d)]
  | ([a, b, c], [d]) => [fn(a, d), fn(b, d), fn(c, d)]
  | ([a, b, c], [d, e, f]) => [fn(a, d), fn(b, e), fn(c, f)]
  | ([a, b, c, d], [e, f, g, h]) => [
      fn(a, e),
      fn(b, f),
      fn(c, g),
      fn(d, h),
    ]
  | ([a, b, c, d], [e]) => [fn(a, e), fn(b, e), fn(c, e), fn(d, e)]
  | _ => [];

let make = (op, x, y) => opVec(op, (x, y));

module Tuple = {
  let list_of_tuple1 = a => [a];
  let list_of_tuple2 = ((a, b)) => [a, b];
  let list_of_tuple3 = ((a, b, c)) => [a, b, c];
  let list_of_tuple4 = ((a, b, c, d)) => [a, b, c, d];
  let tuple_of_list1 =
    fun
    | [a] => a
    | _ => 0;
  let tuple_of_list2 =
    fun
    | [a, b] => (a, b)
    | _ => (0, 0);
  let tuple_of_list3 =
    fun
    | [a, b, c] => (a, b, c)
    | _ => (0, 0, 0);
  let tuple_of_list4 =
    fun
    | [a, b, c, d] => (a, b, c, d)
    | _ => (0, 0, 0, 0);
};

module Revec = {
  include Tuple;
  let add = make((+));
  let multiply = make(( * ));
  let divide = make((/));
  let subtract = make((-));
  module Pervasives = {
    let (+^) = add;
    let ( *^ ) = multiply;
    let (/^) = divide;
    let (-^) = subtract;
  };
};
