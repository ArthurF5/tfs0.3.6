function onSay(cid, words, param, channel)
	local g = getPlayerGUID(cid)
	local k = getHouseByPlayerGUID(g)

	if doSaveHouse({k}) then
		doPlayerSendTextMessage(cid, 22, "Salvo negão.")
	else
		doPlayerSendCancel(cid, "Ish, não foi dessa vez.")
	end
	return true
end
