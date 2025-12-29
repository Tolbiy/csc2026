#pragma once

#include <vector>

namespace csc2026 {

struct Hit {
    double x{};
    double y{};
    double z{};
    double energy{};
};

struct Track {
    double pt{};
    std::vector<Hit> hits{};
};

class TrackReconstructor {
public:
    explicit TrackReconstructor(double minPt);

    void addHit(const Hit& hit);

    std::vector<Track> reconstruct() const;

    const Track* getBestTrack() const;

private:
    double m_minPt{0.0};
    std::vector<Hit> m_hits{};
    mutable Track m_bestTrack{};
};

} // namespace csc2026

