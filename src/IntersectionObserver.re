type t;

[@bs.new]
external make: ([@bs.uncurry] (('callback, 'options) => unit)) => t =
  "IntersectionObserver";

[@bs.send] external observe: (t, Dom.element) => unit = "observe";

[@bs.deriving abstract]
type ioEntry = {
  isIntersecting: bool,
  time: int,
  rootBounds: string,
  boundingClientRect: string,
  intersectionRect: string,
  intersectionRatio: float,
  target: Dom.element,
};