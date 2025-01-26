//
// Created by Wojtek on 26.01.2025.
//

#ifndef SORTVISUALIZER_H
#define SORTVISUALIZER_H
#include <App.h>
#include <ISoundListener.h>
#include <SoundManager.h>


class SortVisualizer : public ISoundListener{
private:
    App& app;
    SoundManager* soundManager;
public:
    explicit SortVisualizer(App& app);
    ~SortVisualizer() override;
    void updateCounters(const int& comparisions, const int& arrayAccesses) const;
    void swapEntities(std::vector<Entity>& entities, int id) const;
    void onPlaySound(const std::string& soundID) override;

};



#endif //SORTVISUALIZER_H
