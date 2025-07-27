# Merge Sort Optimization with Profiling & Charts

This project demonstrates step-by-step optimization of Merge Sort in C, using profiling tools (`perf`, `valgrind`) and visualizing performance using Python.
This project is based on:
> **Performance Engineering of Software Systems**  
> Massachusetts Institute of Technology (MIT) – **6.172**  
> Professors: *Charles E. Leiserson* and *Julian Shun*  
> Homework 2: Profiling Serial Merge Sort*

---

## Files

- `main.c`, `util.c`, `util.h` – Benchmark runner and helpers
- `sort_a.c` – Baseline Merge Sort  
- `sort_c.c` – Coarsened recursion (insertion for small sizes)  
- `sort_f.c` – Reuses a global temp buffer  
- `sort_i.c` – Uses inline functions  
- `sort_m.c` – One malloc (left only)  
- `sort_p.c` – Pointer arithmetic version  
- `Makefile` – Supports `DEBUG=1` or `DEBUG=0` builds  
- `res1.py`, `res2.py` – Bar chart plotters (debug/optimized)

---

## Build & Run

```bash
make             # Optimized build (DEBUG=0)
make DEBUG=1     # Debug build with -g
./sort 10000 10  # Run and benchmark

(visualization)
python3 res1.py   # For DEBUG=1 data
python3 res2.py   # For DEBUG=0 data

(profiling)
perf stat ./sort 10000 10
valgrind --tool=cachegrind ./sort 10000 10
cg_annotate cachegrind.out.* > report.txt
