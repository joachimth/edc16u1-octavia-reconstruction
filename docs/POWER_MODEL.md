# Roadmap: physically-meaningful chain simulation ("virtual dyno")

The chain simulator currently runs the ECU's real KF/KL math on real map data, but with
user-chosen wiring and raw u16 values. The honest path to a *physically meaningful* engine
simulation is a known, validated model — documented by the GPL-3.0 project **ZedSuite**
(github.com/LeZed97/ZedSuite, "power estimation / virtual dyno"). Credited here as the
blueprint; implementing it needs the maps named + scaled (see below).

## The physical chain (full-load fuelling → torque → air → smoke cap → delivered fuel)
1. **Driver Wish** → requested fuel IQ (mg/stroke) at full pedal, vs engine speed.
2. **Torque limiter** (IQ vs RPM × atmospheric pressure) caps the request.
3. **Boost target** map (absolute pressure, mbar) at (IQ, RPM); clamped by SVBL and the
   boost-limit map. Air mass/stroke = ρ(P) · V_cyl · VE(rpm).
4. **Smoke caps**: smoke limiter + IQ-by-MAF (indexed by air mass) + IQ-by-MAP (indexed by
   boost), plus the physical bound fuel ≤ air/AFR_min (≈ air/18 for a diesel before soot).
5. **Injector duration** maps convert IQ → injector on-time (°CA); delivered fuel follows.

## What's needed to make it real on your 016DJ
Each stage above is a *named* map. We have the maps (124 confirmed) and the exact math,
but not yet the reliable name→address binding for 016DJ. Unlocks:
- the **03G906016AA DAMOS** (password-protected rar) — exact family, binds name↔address
  directly; or
- a **WinOLS CSV export** of the 016DG project (DAMOS names) → bind, then project to 016DJ
  via the 360 axis-identical correspondences already computed.

Once the five maps above are identified, the chain simulator becomes a real part-load/full-
load fuelling + boost + smoke model with physical units (rpm, mg/stroke, mbar, °CA).
