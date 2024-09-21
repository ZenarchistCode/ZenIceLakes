modded class ActionConstructor
{
    override void RegisterActions(TTypenameArray actions)
    {
        super.RegisterActions(actions);

        //! ICE SHEETS
        actions.Insert(ActionZenDigIceFishingHole);
        actions.Insert(ActionZenFishingIceHole);
    }
}