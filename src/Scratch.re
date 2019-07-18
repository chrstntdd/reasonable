let fizzBuzz = () =>
  for (i in 1 to 100) {
    let s = string_of_int(i);

    switch (i mod 3, i mod 5) {
    | (0, 0) => s ++ " => FizzBuzz"
    | (_, 0) => s ++ " => Fizz"
    | (0, _) => s ++ " => Buzz"
    | _ => s
    };
  };

let fibonacci = n => {
  let a = ref(0);
  let b = ref(1);
  for (_ in 2 to n) {
    let tmp = ref(a^);
    a := b^;
    b := a^ + tmp^;
  };
  b^;
};

module StringMap = Map.Make(String);

let rec naiveFibRecur = n =>
  n <= 1 ? n : naiveFibRecur(n - 1) + naiveFibRecur(n - 2);

let fibonacciRecur = n => {
  let rec inner = (num, cache) =>
    num <= 1 ?
      num :
      (
        switch (StringMap.find(string_of_int(num), cache^)) {
        | exception Not_found =>
          let result = inner(num - 1, cache) + inner(num - 2, cache);

          cache :=
            StringMap.add(string_of_int(num), string_of_int(result), cache^);

          result;
        | res => int_of_string(res)
        }
      );

  inner(n, ref(StringMap.empty));
};