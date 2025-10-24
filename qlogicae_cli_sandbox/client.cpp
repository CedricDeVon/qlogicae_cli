#include <nanobench.h>
#include <future>
#include <boost/asio.hpp>
#include <unifex/static_thread_pool.hpp>
#include <unifex/then.hpp>
#include <unifex/just.hpp>
#include <unifex/on.hpp>
#include <unifex/sync_wait.hpp>
#include <unifex/spawn_detached.hpp>
#include <thread>
#include <vector>

using namespace ankerl::nanobench;

inline void work() noexcept {
    volatile int n = 0;
    for (int i = 0; i < 1'000'000; ++i) n += i;
}

void bench_async() {
    std::async(std::launch::async, [] { work(); }).get();
}

void bench_asio() {
    static boost::asio::thread_pool pool(std::thread::hardware_concurrency());
    boost::asio::post(pool, [] { work(); });
}

void bench_unifex_baseline() {
    static unifex::static_thread_pool pool(std::thread::hardware_concurrency());
    unifex::sync_wait(
        unifex::on(
            pool.get_scheduler(),
            unifex::then(unifex::just(), [] { work(); })
        )
    );
}

void bench_unifex_optimized() {
    static unifex::static_thread_pool pool(std::thread::hardware_concurrency());
    static auto sender = unifex::on(
        pool.get_scheduler(),
        unifex::then(unifex::just(), [] { work(); })
    );
    unifex::sync_wait(sender);
}

int main() {
    Bench bench;
    bench.title("Async Backends Nanobenchmark");
    bench.relative(true);
    bench.minEpochIterations(2000);

    bench.run("std::async", bench_async);
    bench.run("Boost.Asio", bench_asio);
    bench.run("libunifex (baseline)", bench_unifex_baseline);
    bench.run("libunifex (optimized)", bench_unifex_optimized);
    
    return 0;
}
