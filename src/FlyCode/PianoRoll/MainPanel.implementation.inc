


procedure TPianoRoll.BuildMainPanel; 
begin
	PatternSelector:= TPatternSelector.Create(MainPanel);
    PatternSelector.callReload:= nil;
    PatternSelector.buildPatternSelector;
    PatternSelector.reloadPatternSelector(0); 
end;