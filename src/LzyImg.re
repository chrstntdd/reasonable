open Belt;

type image_kind =
  | BgImg
  | Img;

let handler = (x, _) =>
  switch (x) {
  | [|entry|] =>
    Js.log("Just the one tho");
    Js.log(entry);
  | _ => Js.log("aything else")
  };
();

[@react.component]
let make = (~src, ~kind, ~alt) => {
  let rootRef = React.useRef(Js.Nullable.null);

  React.useEffect1(
    () => {
      let io = IntersectionObserver.make(handler);

      rootRef
      ->React.Ref.current
      ->Js.Nullable.toOption
      ->Option.map(rootRef => IntersectionObserver.observe(io, rootRef))
      ->ignore;

      None;
    },
    [||],
  );

  switch (kind) {
  | Img => <img data="" alt ref=rootRef->ReactDOMRe.Ref.domRef />
  | BgImg => <div title=alt ref=rootRef->ReactDOMRe.Ref.domRef />
  };
};