/* Scratch.fizzBuzz(); */
/* Js.log(Scratch.fibonacci(10)); */
Js.log(Scratch.fibonacciRecur(10));
/* Js.log(Scratch.naiveFibRecur(50)); */

type state = {inputValue: string};

type action =
  | Change(string);

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  switch (url.path) {
  | [] => Js.log("AT THE ROOT")
  | ["something"] => Js.log("AT SOMETHING")
  | _ => Js.log("NOT FOUND")
  };

  let (_, dispatch) =
    React.useReducer(
      (_, action) =>
        switch (action) {
        | Change(inputValue) => {inputValue: inputValue}
        },
      {inputValue: ""},
    );

  <div>
    <input
      onChange={
        _event => dispatch(Change(_event->ReactEvent.Form.target##value))
      }
    />
    <LzyImg kind=LzyImg.Img src="" alt="" />
    <button onClick={_event => ReasonReactRouter.push("/something")}>
      {ReasonReact.string("Go to something")}
    </button>
    <button onClick={_event => ReasonReactRouter.push("/")}>
      {ReasonReact.string("Go to root")}
    </button>
  </div>;
};